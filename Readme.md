You can run this code using Code Blocks. You should change the path to get the image tank.jpg.

This OpenCV code will load the image first and compute its dft. The central part in the resulting image in the frequency domain will be omitted (set to zero).
The minimum part of the image is a function of L. Multiple values of L were tried out until reaching Lmin at which the image is noticeably degraded.

The same thing is repeated using the dct but the part kept from the image is only for (0<=K1<L and 0<=K2<L).
Again the minimum L is at which the image is noticeable degraded.

The resulting images from the inverse dft and the inverse DCT along with the original image are displayed. 
Pressing any key will close the windows.



