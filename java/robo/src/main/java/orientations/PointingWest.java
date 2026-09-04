package main.java.orientations;

import main.java.Position;

public class PointingWest implements RobotOrientation {

    private final RobotOrientation left;
    private final RobotOrientation right;

    public PointingWest(RobotOrientation south) {

        this.left = south;
        this.right = pointNorth();

    }

    @Override
    public String showSymbol() { return "W"; }

    @Override
    public Position move(Position currentPosition) {
        currentPosition.setX(currentPosition.getX() - 1);
        return currentPosition;
    }

    @Override
    public RobotOrientation turnLeft() { return left; }

    @Override
    public RobotOrientation turnRight() { return right; }

    @Override
    public RobotOrientation pointNorth() { return left.pointNorth(); }

    public RobotOrientation pointWest() { return this; }
}
