package main.java.orientations;

import main.java.Position;

public interface RobotOrientation {

    String showSymbol();

    Position move(Position currentPosition);

    RobotOrientation turnLeft();

    RobotOrientation turnRight();

    RobotOrientation pointNorth();

    RobotOrientation pointWest();

}
