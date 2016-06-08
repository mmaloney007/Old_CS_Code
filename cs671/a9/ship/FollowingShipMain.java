
// Time-stamp: <06 Nov 2001 at 19:10:59 by charpov on berlioz.cs.unh.edu>

public class FollowingShipMain {
    public static void main (String[] args) {
        FollowingShip pinta = new FollowingShip("Pinta",0,0);
        pinta.setCourse(40);
        pinta.accelerate(2.0);
        pinta.move(3.0);
        pinta.status();
        FollowingShip nina = new FollowingShip("Nina",0,0);
        nina.accelerate(3.0);
        nina.setCourse(50);
        nina.move(2.0);
        nina.status();
        nina.follows(pinta);
        nina.status();
        System.out.println(nina.distance(pinta));
        pinta.move(5.0);
        System.out.println(nina.distance(pinta));
        FollowingShip santaMaria = new FollowingShip("SantaMaria",0,0);
        pinta.status();
        santaMaria.status();
        System.out.println(santaMaria.distance(pinta));
        santaMaria.follows(nina);
        try {
            nina.move(3.0);
        }
        catch (ShipException e) {
            System.out.println(e);
        }
        pinta.setCourse(70);
        pinta.move(2.0);
        System.out.println(pinta.distance(nina));
        System.out.println(pinta.distance(santaMaria));
        try {
            pinta.follows(santaMaria);
        }
        catch (ShipException e) {
            System.out.println(e);
        }
        nina.detach();
        nina.status();
        santaMaria.status();
        pinta.status();
        pinta.follows(santaMaria);
        nina.decelerate(1.0);
        nina.move(3.0);
        pinta.detach();
        santaMaria.status();
        pinta.status();
    }
}

/* Output:

   Pinta: Position = (3.86, 4.6)  Speed = 2.0  Course = 40
   Nina: Position = (4.6, 3.86)  Speed = 3.0  Course = 50
   Nina: Position = (4.6, 3.86) following Pinta (speed = 2.0 course = 40)
   1.0458689129718983
   1.045868912971899
   Pinta: Position = (10.28, 12.26)  Speed = 2.0  Course = 40
   SantaMaria: Position = (0.0, 0.0)  Speed = 0.0  Course = 0
   16.0
   ShipException: Cannot move following ship!
   1.045868912971899
   16.0
   ShipException: Cannot create a cycle!
   Nina: Position = (14.78, 12.89)  Speed = 2.0  Course = 70
   SantaMaria: Position = (3.76, 1.37) following Nina (speed = 2.0 course = 70)
   Pinta: Position = (14.04, 13.62)  Speed = 2.0  Course = 70
   SantaMaria: Position = (6.58, 2.39) following Nina (speed = 1.0 course = 70)
   Pinta: Position = (16.86, 14.65)  Speed = 1.0  Course = 70
*/
