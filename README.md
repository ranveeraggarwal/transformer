#TRANSFORMER
The report for this bot can be found at http://www.cse.iitb.ac.in/~ranveer/graphics_2_1/

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
* `Q`: Increase X
* `A`: Decrease X
* `W`: Increase Y
* `S`: Decrease Y
* `E`: Increase Z
* `D`: Decrease Z

###Camera Controls
* `M`: Zoom In
* `N`: Zoom Out
* Arrow Keys : Rotate Camera

##Transformation
* `Space`: Transform/Revert
* `F`: Move forward when transformed
* `B`: Move backward when transformed

##External libraries used
* SOIL (Simple OpenGL Image Library): We used this to load images into our program.
* GLU: We didn't make much use of it, except for changing the lookat (gluLookat).

##References
* We learnt texture mapping throught this site: http://nehe.gamedev.net/tutorial/texture_mapping/12038/
* Our transformer was inspired from this video: https://www.youtube.com/watch?v=9Q754HvR_3k