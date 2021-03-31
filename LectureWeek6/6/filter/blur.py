# Blurs an image

from PIL import Image, ImageFilter  # Pillow filter

# Blur image
before = Image.open("bridge.bmp")  # Open the original file
after = before.filter(ImageFilter.BLUR)  # blur the image
after.save("out.bmp")  
