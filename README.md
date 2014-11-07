#TRANSFORMER
The report for this bot can be found at http://www.cse.iitb.ac.in/~ranveer/graphics/
The video can be found at https://www.youtube.com/watch?v=-1trKrV04yE

##Movements
The components of the transformer's body are mapped to keys. Pressing one of these keys will activate the corresponding component.

###Here are the key mappings (More to be added):
* `Z`: Waist
* `G`: Right Shoulder
* `T`: Left Shoulder
* `H`: Right Elbow
* `Y`: Left Elbow
* `J`: Right Wrist
* `U`: Left Wrist
* `K`: Right Hip
* `I`: Left Hip
* `L`: Right Knee
* `O`: Left Knee
* `;`: Right Ankle
* `P`: Left Ankle
* `X`: Neck

###To move the active component, the following key mappings work:
* `Shift + Q`: Increase X
* `Shift + A`: Decrease X
* `Shift + W`: Increase Y
* `Shift + S`: Decrease Y
* `Shift + E`: Increase Z
* `Shift + D`: Decrease Z

###Camera Controls

Press the number keys to select the corresponding camera

* Camera 0 : Orthographic Camera
- 'Left Arrow Key' : Rotate Camera Clockwise
- 'Right Arrow Key' : Rotate Camera Counter Clockwise

* Camera 1 : Perspective Camera (Default)
- `M`: Zoom Out
- `N`: Zoom In
- Arrow Keys: Rotate Camera
- Shift + Array Keys: Move Camera
- 'V': Toggle camera focus on the Transformer

* Camera 2 : Perspective Camera behind and above the transformer. Follows the transformer.

* Camera 3 : First Person View of the transformer when transformed in to a truck.

##Lighting
* `R`: Toggle Day/Night
* `H`: Toggle Headlights
* `C`: Toggle just the moon light. (By default, moon light is during night only).

##Transformation and Movement
* `Space`: Transform/Revert
* `W`: Move Forward
* `S`: Move backward
* `A`: Turns Left when holding this and moving forward/backward
* `D`: Turns Right when holding this and moving forward/backward

##Recording & Playback
* `B`: Save a keyframe
* `F`: Increase number of interpolating frames by the multiplier
* `Shift+F`: Decrease number of interpolating frames by the multiplier
* `Shift+.(>)`: Increase the multiplier by 1
* `Shift+,(<)`: Decrease the multiplier by 1
* `Shift+B`: Start playback

* The first command line argument specifies the fps (of course, the maximum fps is limited by the hardware).
* All boolean values change only when the keyframe is reached.
* All other interpolations are linear. Angles are interpolated in the direction of minimum distance.
* The number of interpolating frames is reset to 0 when a keyframe is saved.

##External libraries used
* SOIL (Simple OpenGL Image Library): We used this to load images into our program.
* GLU: We didn't make much use of it, except for changing the lookat (gluLookat).

##References
* We learnt texture mapping throught this site: http://nehe.gamedev.net/tutorial/texture_mapping/12038/
* Our transformer was inspired from this video: https://www.youtube.com/watch?v=9Q754HvR_3k
