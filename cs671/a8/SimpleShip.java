//Victor Maloney Java implementaion one of assignment one
//November 5, 2001
public class SimpleShip {

    private double xpos;  //x position on a graph
    private double ypos;  //y position on a graph
    private int course;  //degrees of the course
    private double speed;  //speed of the ship

   //Move the ship for a time
   public void move(double time)
   {
    double d = Math.toRadians(course);
    xpos += (time * speed * Math.sin(d));
    ypos += (time * speed * Math.cos(d));
   }

   //speed the ship up by speed
   public void accelerate(double speed)
   {
    this.speed += speed;
   }

   //slow the ship down by a speed
   public void decelerate(double speed)
   {
    this.speed -= speed;
   }

   //stop the ship
   public void stop()
   {
    speed = 0;
   }
  
   //set the ships course
   public void setCourse(int course)
   {
    this.course = course;
   }
  
   //get the ships position
   public double[] getPos()
   {
    double[] a = new double[2];

    a[0] = xpos;
    a[1] = ypos;

    return a;
   }
   
   //get the ships course
   public int getCourse()
   {
    return course;
   }
  
   //get the ships speed
   public double getSpeed()
   {
    return speed;
   }

   //print out the status of the ship
   public void status()
   {
    System.out.println("Position = (" + xpos + ",  " + ypos + ") Speed = " + speed + " Course = " + course );
   }
 
   //find the distance to another ship
   public double distance(SimpleShip a)
   {
     double c = (this.xpos - a.xpos);
     double b = (this.ypos - a.ypos);
     return Math.sqrt((c*c) + (b*b));
   }

   //make a simple ship starting at the origin
   public SimpleShip()
   {
     xpos = 0;
     ypos = 0;
     course = 0;
     speed = 0;
    }

    //make a simple ship starting at xpos and ypos
    public SimpleShip(double xpos, double ypos)
    {
     this.xpos = xpos;
     this.ypos = ypos;
     course = 0;
     speed = 0;
    }
}
