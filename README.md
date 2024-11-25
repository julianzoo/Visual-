# Visual Computing PS 2024/2025
Here we develop code for the UIBK Bachelors seminar Visual Computing (WS2024/25).

##  Contributors
- Bodanov, Yevhenii
- Frei, Julian
- Tiefenthaler, Matthias

## User Control Assignment_03
The Plane does not align its direction correctly while the user is steering.
Therefore we added a code section within the sceneUpdate() section, which can be commented out to have a look at the steering isolated, i.e. without the planes nose aligned while circling the orbit center. <br>
The following present the key commands and its effects:
- 'a' and 'd' for steering the plane left and right (yaw and roll are combined)
- 'w' and 's' for accelerating and decelerating, respectively 
- 'ctrl' and 'space' for pitch down and up
- '1' and '2' for selecting basic camera and additional third-person-camera (more of a close-by camera, following the plane)