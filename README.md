# UnrealSpectatorPlugin

This is a small plugin to control shifting between static camera views and other player views in Unreal Engine.

![Demo Gif](Resources/Demo.gif)

## That's a simple task.  Why a plugin?

There are a few edge cases this plugin covers.

1. Change blend time easily.
1. Add a spectatable in multiplayer scenarios.
1. Any number of spectatable actors in your level.
1. Any number of spectators.
1. Spectators register on begin play- no manual setup.

## How to use

1. Add the `USpectatorComponent` to one of your playable pawns.
1. Add actors with the `USpectatableComponent` component to the map.
    1. Give them a friendly name.
    1. Give them an icon, maybe?
1. Create a subclass of `USpectatorComponentWidget`.
1. Create an instance of your new widget class.
1. Call the `Setup` function on the new widget.

## Sample Map

There's a sample map with everything minimally set up to get you started.

## Potential Problems

If you don't own the widget studio asset from the marketplace, you should remove it from the dependencies and comment out the `WSSpectatorComponentWidget`.
