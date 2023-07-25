import os
import caer 
import canaro
import numpy as np
import cv2 as cv
import gc
import matplotlib.pyplot as plt
from tensorflow.keras.utils import to_categorical

# Settings / Attributes 
IMG_SIZE = (80, 80)
BATCH_SIZE = 32
EPOCHS = 10
channels = 1
char_path = r'C:\Users\da9350\projects\Work-Bench\Open_CV\faces\simpsons-dataset\simpsons_dataset'

# Get characters
char_dict = {}
for char in os.listdir(char_path):
    char_dict[char] = len(os.listdir(os.path.join(char_path,char)))

# Sort in descending order 
char_dict = caer.sort_dict(char_dict, descending=True)
print(char_dict)

# Store first ten characters list
characters = []
count = 0
for i in char_dict:
    characters.append(i[0])
    count += 1
    if count >= 10:
        break
print(characters)

# Create the training data
train = caer.preprocess_from_dir(char_path, characters, channels=channels, IMG_SIZE=IMG_SIZE, isShuffle=True)
print(len(train))

# Show first image of training data 
gray = cv.cvtColor(train[0][0], cv.COLOR_BGR2GRAY)
cv.imshow('Image 1', gray)

# Seperate training set
featureSet, labels = caer.sep_train(train, IMG_SIZE=IMG_SIZE)

# Normalize the featureSet ==> (0,1)
featureSet = caer.normalize(featureSet)
labels = to_categorical(labels, len(characters))

# Train and validate
x_train, x_val, y_train, y_val = caer.train_val_split(featureSet, labels, val_ratio=0.2)

# Save memeory by deleting unused variables
del train
del featureSet
del labels
gc.collect()

# Image data generator
datagen = canaro.generators.imageDataGenerator()
train_gen = datagen.flow(x_train, y_train, batch_size=BATCH_SIZE)

# Creating the model
model = canaro.models.createSimpsonsModel(IMG_SIZE=IMG_SIZE, channels=channels, output_dim=len(characters), 
                                          loss='binary_crossentropy', decay=1e-6, learning_rate=0.001, 
                                          momentum= 0.9, nesterov=True)

print(model.summary())