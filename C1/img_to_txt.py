from skimage import io, util

# Load an image
image_path = 'cat.jpg'
image = io.imread(image_path)

# Convert image to a flat array of pixel values
pixel_data = util.img_as_ubyte(image[:,:,:3].flatten())

# Save pixel data to a file
output_file = 'input_img.txt'
pixel_data.tofile(output_file, sep='\n', format='%d')