# LogAnimationTransitionRules
## Example of how to use the visual logger to better follow the flow of animation transitions.

The [Visual Logger](https://docs.unrealengine.com/latest/INT/Gameplay/Tools/VisualLogger/) is a powerful Unreal Engine tool.
It allows you to easily have access to a temporal log on your project.


![](https://docs.unrealengine.com/latest/images/Gameplay/Tools/VisualLogger/image_0.jpg)


As explained by Epic, the Visual Logger is great to debug gameplay bugs, particularly AI related ones.

But it is not restricted to that purpose, and its ability to be used with any kind of actor based class makes it very flexible.

Based on the third person code sample project provided by Epic, here you can find some examples of how to use it to log some of the character's variables (location and rotation) through time.


![](http://i.imgur.com/490Pr40.png)


When an animation blueprint grows larger, and its state machine gets more complex, it gets harder to debug and keep track of what happened over a period of time.

The Visual Logger is perfect for this situation. One if its possible uses is for logging which transitions where taken, and when.

The LogAnimationTransition function found in USampleAnimInstance will create a new node which can be added before the exit node of an animation transition rule.

Whenever that transition is followed, it will be logged. 
       

![](http://i.imgur.com/CWPf8wP.png)
