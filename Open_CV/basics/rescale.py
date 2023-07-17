import cv2 as cv


# Rescale the image or video 
def rescaleFrame(frame, scale=0.75):
    # Images, Videos and Live Video
    width = int(frame.shape[1] * scale)
    height = int(frame.shape[0] * scale)
    dimensions = (width, height)

    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)

# Rescale the resolution of a video
def changeRes(width, height):
    # Live video
    capture.set(3, width)
    capture.set(4, height)

# Show image and rescaled image
img = cv.imread('Resources/Photos/cat.jpg')
cv.imshow('Cat', img)

resized_image = rescaleFrame(img)
cv.imshow('Image', resized_image)


# Play video and rescaled video
capture = cv.VideoCapture('Resources\Videos\dog.mp4')

while True:
    isTrue, frame = capture.read()

    frame_resized = rescaleFrame(frame)

    cv.imshow('Video', frame)
    cv.imshow('Video Resized', frame_resized)

    if cv.waitKey(20) & 0xFF==ord('d'):
        break

capture.release()
cv.destroyAllWindows()