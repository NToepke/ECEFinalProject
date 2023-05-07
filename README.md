# ECE Final Project
Final project for ECE3220

Team Members:
Thomas Hagedorn
Nathan Toepke

Our final project focused on creating an escape room experience within the scope of this project, which allows players
to explore through interacting with various objects and characters in rooms.

What our project features:
A singleton design pattern focused on player progression throughout the story.
A factory design pattern focused on creation of game objects for the player to interact with.
Modularity for loading new stories with an easy to modify file loading system.
GTests used to verify the stability of our project's code.
Docker container compatibility to allow for our project to be easily deployed on any environment.

To run our project: Utilize the docker container provided at this link: 
or use the command: docker build -t escaperoom .
after cloning down the github repo to your local machine.

then run the container as an interactable image
by running the command: docker run --rm -it escaperoom