//Part three
public class NamedShip extends SimpleShip{

    private String name; //name of ship

    public void status()
    {
     double[] a = getPos();

     System.out.println(name + ": " + "Position = (" + a[0] + ", " + a[1] + ") Speed = " + getSpeed() + " Course = " + getCourse());
    }
 
    public NamedShip()
    {
     super();
     name = "Ship 01";
    }

    public NamedShip(double xpos, double ypos)
    {
      super(xpos, ypos);
      name = "Ship 01";
    }
   
    public NamedShip(String name)
    {
     super();
     this.name = name;
    }
   
    public NamedShip(String name, double xpos, double ypos)
    {
      super(xpos, ypos);
      this.name = name;
    }
}
