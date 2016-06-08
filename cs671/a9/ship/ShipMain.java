public class ShipMain{
    public static void main (String[] args) {
        double x=0.0, y=0.0;
	if (args.length > 0) x = Double.parseDouble(args[0]);
   	if (args.length > 1) y = Double.parseDouble(args[1]);
   	SimpleShip pinta = new SimpleShip(x,y);
 	pinta.setCourse(40);
	pinta.accelerate(2.0);
	pinta.move(3.0);
	pinta.status();
	NamedShip nina = new NamedShip("Nina",x,y);
	SimpleShip ghost = nina;
	nina.accelerate(3.0);
	nina.setCourse(50);
	nina.move(2.0);
	nina.status();
	ghost.status();
	pinta = new NamedShip("Pinta");
	NamedShip santaMaria = new NamedShip(x,y);
	System.out.println(santaMaria.distance(pinta));
	santaMaria.accelerate(3.0);
	santaMaria.setCourse(300);
	pinta.setCourse(santaMaria.getCourse());
	pinta.stop();
	pinta.accelerate(santaMaria.getSpeed());
	santaMaria.move(2.0);
	pinta.move(2.0);
	System.out.println(pinta.distance(santaMaria));
	SimpleShip[] allShips = {pinta,nina,santaMaria,ghost};
	for (int i=0;i<allShips.length;i++)
		allShips[i].status();
   }
}
