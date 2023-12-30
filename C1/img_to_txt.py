from skimage import io, util

# Load an image
image_path = 'cat.jpg'
image = io.imread(image_path)

print(image.shape[0])
print(image.shape[1])
print(image.shape[2])
# channel
# row
# column
# open file and insert data
# normalize the pixel values before insertion
file = open('input_img.txt', 'w')
for k in range(image.shape[2]):
    for i in range(image.shape[0]):
        for j in range(image.shape[1]):
            file.write(str(image[i][j][k]/10) + '\n')
file.close()