#include <cmath>
#include <iostream>
#include <map>
using namespace std;

struct Coor {
    int x, y;

    Coor(int x, int y) : x{x}, y{y} {}
    ~Coor() {}
};

ostream &operator<<(ostream &out, Coor c) {
    out << " (" << c.x << "," << c.y << ") ";
    return out;
}

enum class Direction { NORTH, EAST, SOUTH, WEST };

ostream &operator<<(ostream &out, Direction d) {
    if (d == Direction::NORTH) {
        out << " North ";
    } else if (d == Direction::SOUTH) {
        out << "  South ";
    } else if (d == Direction::EAST) {
        out << " East ";
    } else {
        out << " West ";
    }
    return out;
}

class Robot {
    Coor curLocation;
    Coor beaconLocation;
    Coor lowerLeftBound;
    Coor upperRigthBound;
    bool didBeacon;

    Direction curDirection;

    const int NUM_DIRECTIONS;
    map<Direction, int> dMap;
    Direction directions[4];

    void updateBound() {
        lowerLeftBound = {min(curLocation.x, lowerLeftBound.x),
                          min(curLocation.y, lowerLeftBound.y)};
        upperRigthBound = {max(curLocation.x, upperRigthBound.x),
                           max(curLocation.y, upperRigthBound.y)};
    }

    int calDistanceToBeacon() {
        if (!didBeacon) {
            return 0;
        }
        return sqrt(pow(curLocation.x - beaconLocation.x, 2) +
                    pow(curLocation.y - beaconLocation.y, 2));
    }

  public:
    Robot()
        : curLocation{0, 0}, beaconLocation{0, 0}, lowerLeftBound{0, 0},
          upperRigthBound{0, 0}, didBeacon{false},
          curDirection{Direction::NORTH}, NUM_DIRECTIONS{4} {
        dMap[Direction::NORTH] = 0;
        dMap[Direction::EAST] = 1;
        dMap[Direction::SOUTH] = 2;
        dMap[Direction::WEST] = 3;

        directions[0] = Direction::NORTH;
        directions[1] = Direction::EAST;
        directions[2] = Direction::SOUTH;
        directions[3] = Direction::WEST;
    }
    void turnLeft() {
        int curDirectionIndex = dMap[curDirection];
        int updatedDirectionIndex =
            curDirectionIndex - 1 < 0 ? 3 : curDirectionIndex - 1;
        int i = (updatedDirectionIndex) % NUM_DIRECTIONS;
        curDirection = directions[i];
    }

    void turnRight() {
        int curDirectionIndex = dMap[curDirection];
        int i = (curDirectionIndex + 1) % NUM_DIRECTIONS;
        curDirection = directions[i];
    }

    void goForward(int distance) {
        if (distance < 0) {
            cerr << "ERROR: invalid distance" << endl;
            return;
        }

        if (curDirection == Direction::NORTH) {
            curLocation.y += distance;
        } else if (curDirection == Direction::SOUTH) {
            curLocation.y -= distance;
        } else if (curDirection == Direction::EAST) {
            curLocation.x += distance;
        } else {
            curLocation.x -= distance;
        }

        updateBound();
    }

    void placeBeacon() {
        if (didBeacon) {
            cerr << "ERROR: beacon already placed" << endl;
            return;
        }
        didBeacon = true;

        beaconLocation = {curLocation.x, curLocation.y};
    }

    void pickupBeacon() {
        if (!didBeacon) {
            cerr << "ERROR: beacon is not placed" << endl;
        }
        didBeacon = false;
    }
    void reset() {
        curLocation = {0, 0};
        lowerLeftBound = {0, 0};
        upperRigthBound = {0, 0};
        didBeacon = false;
        curDirection = Direction::NORTH;
    }
    void printStatus() {
        cout << "--------------------------------------------" << endl;
        cout << "Robot is at" << curLocation << "and is facing" << curDirection
             << endl;

        cout << "the distance to the beacon is: " << calDistanceToBeacon()
             << endl;

        cout << "the bounding box is" << lowerLeftBound << "-"
             << upperRigthBound << endl;
        cout << "--------------------------------------------" << endl;
        cout << endl;
    }
};

int main() {
    Robot r;
    r.printStatus();
    cout << "***************** Testing Forward *********************" << endl;
    r.goForward(5);
    r.printStatus();
    r.goForward(-5);
    r.printStatus();
    r.reset();
    cout << "***************** Testing Right *********************" << endl;
    r.turnRight();
    r.goForward(1);
    r.printStatus();
    r.turnRight();
    r.goForward(1);
    r.printStatus();
    r.turnRight();
    r.goForward(1);
    r.printStatus();
    r.turnRight();
    r.goForward(1);
    r.printStatus();
    r.reset();
    cout << "***************** Testing Left *********************" << endl;
    r.turnLeft();
    r.goForward(1);
    r.printStatus();
    r.turnLeft();
    r.goForward(1);
    r.printStatus();
    r.turnLeft();
    r.goForward(1);
    r.printStatus();
    r.turnLeft();
    r.goForward(1);
    r.printStatus();
    r.reset();
    cout << "***************** Testing Place Beacon ****************" << endl;
    r.placeBeacon();
    r.goForward(1);
    r.printStatus();
    r.placeBeacon();
    r.reset();
    r.placeBeacon();
    r.printStatus();
    r.reset();
    cout << "***************** Testing Pickup *********************" << endl;
    r.placeBeacon();
    r.goForward(1);
    r.printStatus();
    r.pickupBeacon();
    r.printStatus();
    cout << "***************** Testing Reset *********************" << endl;
}
