import os
import caer 
import canaro
import numpy as np
import cv2 as cv
import gc
import matplotlib.pyplot as plt

# Settings / Attributes 
IMG_SIZE = (80, 80)
channels = 1
char_path = r'C:\Users\da9350\projects\Work-Bench\Open_CV\faces\simpsons-dataset\simpsons_dataset'

# Get characters
char_dict = {}
for char in os.listdir(char_path):
    char_dict[char] = len(os.listdir(os.path.join(char_path.char)))

# Sort in descending order 
char_dict = caer.sort_dict(char_dict, descending=True)
print(char_dict + "\n")

# Store first ten characters list
characters = []
count = 0
for i in char_dict:
    characters.append(i[0])
    count += 1
    if count >= 10:
        break
print(characters + "\n")

# Create the training data
train = caer.preprocess_from_dir(char_path, characters, channels=channels, IMG_SIZE=IMG_SIZE, isShuffle=True)
print(len(train + "\n"))

# Show first image of training data 
gray = cv.cvtColor(train[0][0], cv.COLOR_BGR2GRAY)
cv.imshow('Image 1', gray)