package main.java.orientations;

import main.java.Position;

public class PointingEast implements RobotOrientation {

    private final RobotOrientation left;
    private final RobotOrientation right;

    public PointingEast(RobotOrientation north) {

        this.left = north;
        this.right = new PointingSouth(this);

    }

    @Override
    public String showSymbol() { return "E"; }

    @Override
    public Position move(Position currentPosition) {
        currentPosition.setX(currentPosition.getX() + 1);
        return currentPosition;
    }

    @Override
    public RobotOrientation turnLeft() { return left; }

    @Override
    public RobotOrientation turnRight() { return right; }

    @Override
    public RobotOrientation pointNorth() { return left.pointNorth(); }

    @Override
    public RobotOrientation pointWest() { return right.pointWest(); }
}
