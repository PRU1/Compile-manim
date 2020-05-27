# Compile-manim
A more user-friendly way to compile Manim using an MFC dialog application (currently Windows only, sorry)


## Installation Instructions
**This does not install [Manim](https://github.com/3b1b/manim), you need to have Manim working for this** 
1. Clone this repository, put this ```git clone https://github.com/PRU1/Compile-manim.git``` in bash
2. (Recommended) Make a folder and put manimCompile2.exe 
3. Open manimCompile2.exe
4. Press render. This should give an error
5. Go to file explorer and go to the location of manimCompile2.exe
6. You'll notice that there is a new file created called manimCompile2-manimPath.in. Open this file using notepad
7. In this file, type in your Manim directory path (i.e. C:/Users/bob/manim)
8. Save and close this file. Do not delete this file or change its file name or the application will not work
9. Now you can use the app!

## Learn the controls

![Image of application](https://github.com/PRU1/Compile-manim/blob/master/applicationImage.png)


## Things that need to be changed

1. Make cross-platform

## Bugs

For some reason, this application needs the user to input the file location twice for it to be registered
