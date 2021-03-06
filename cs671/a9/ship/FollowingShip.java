//A class of ships that can follow each other
public class FollowingShip extends NamedShip{
        
        private String name;
        private FollowingShip fship; //ship following this ship
        private FollowingShip lship; //ship leading this ship
        private int follow; //set to zero if not following already 
	private int lead; //set to zero if not leading already
        private int shipnum;  //keeps the number of ships
        private static int ships;

	public FollowingShip(String name)
        {
         super(name);
         this.name = name;
         fship = null;
         lship = null;
         follow = 0;
         lead = 0;
         shipnum = ships;
         ships++;
        }
        
        public FollowingShip(String name, double xpos, double ypos)
        {
         super(name,xpos,ypos);
         this.name = name;
         fship = null;
         lship = null;
         follow = 0;
         lead = 0;
         shipnum = ships;
         ships++;
        }
 
        //Make a ship that follows another one
        public FollowingShip(double xpos, double ypos)
        {
         super(xpos,ypos); 
         this.name = ("Ship " + ships);
         fship = null;
         lship = null;
         follow = 0;
         lead = 0;
         shipnum = ships;
         ships++;
        }

        //have one ship follow another ship
        public void follows(FollowingShip aShip)
        {
         FollowingShip s = aShip;
         while(s != null)
         {
          if(this.shipnum == s.shipnum)
          {
           throw new ShipException("Can't create a cycle!");
          }
         else
         {
          s = s.fship;
         }
        }
        s = aShip;
        while(s != null)
        { 
          if(this.shipnum == s.shipnum) {
           throw new ShipException("Can't create a cycle!");
          }
          else {
           s = s.lship;
          }
         }
         if(this.follow != 0) //check to see if following anyone
         {
          throw new ShipException("Already following someone!");
         }
         else
         {
          if(aShip.lead == 0) //check to see if leading anyone
          {
           super.stop();
           aShip.fship = this;
           this.lship = aShip;
           
           double b;
           int c;

           b = aShip.getSpeed();
           c = aShip.getCourse();

           this.setCourse(c);
           this.accelerate(b);

           aShip.lead = 1;
           this.follow = 1;
          }
          else
          {
           throw new ShipException("Already being a leader! 74");
          }
         }
        }

        //detach a ship from another ship
        public void detach()
        {
         if(this.follow != 0)
         {
          this.follow = 0;
          this.lship.fship = null;
          this.lship.lead = 0;
          this.lship = null;
         }
         else
         {
          throw new ShipException("Not following anything!");
         }
        }

        //accelerate
        public void accelerate(double acc)
        {
         if(this.follow != 0)
         {
          throw new ShipException("Can't acclerate ship!");
         }
         else if(this.lead != 0)
         {
          fship.accelerate1(acc);
          super.accelerate(acc);
         }
         else 
         {
          super.accelerate(acc);
         }
        }

        //accelerate a following ship
        private void accelerate1(double acc)
        {
         super.accelerate(acc);
        }

        //decelerate
        public void decelerate(double dec)
        {
         if(this.follow != 0)
         {
          throw new ShipException("Can't decelerate a following ship!");
         }
         else if(this.lead != 0)
         {
          fship.decelerate1(dec);
          super.decelerate(dec);
         }
         else
         {
          super.decelerate(dec);
         }
        }

        private void decelerate1(double dec)
        {
         super.decelerate(dec);
        }

        //public move
        public void move(double time)
        {
         if(this.follow != 0)
         {
          throw new ShipException("Can't move a following ship!");
         }
         else if(this.lead != 0)
         {
          fship.move1(time);
          super.move(time);
         }
         else
         {
          super.move(time);
         }
        }
   
        //private move for following ship
        private void move1(double time)
        {
         if(this.lead != 0)
         {
          fship.move1(time);
         }
         super.move(time);
        }
 
        //stop the ships
        public void stop()
        {
         if(this.follow != 0)
         {
          throw new ShipException("Can't stop a following ship!");
         }
         else if(this.lead != 0)
         {
          fship.stop1();
          super.stop();
         }
         else
         {
          super.stop();
         }
        }
  
        //move helper
        private void stop1()
        {
         if(this.lead != 0)
         {
          fship.stop1();
         }
         super.stop();
        }

        //set the course of ships
        public void setCourse(int course)
        {
         if(this.follow != 0)
         {
          throw new ShipException("Can't set course following another ship!");
         }
         else if(this.lead != 0)
         {
          fship.setCourse1(course);
          super.setCourse(course);
         }
         else
         {
          super.setCourse(course);
         }
        }

        //SetCourse Helper
        private void setCourse1(int course)
        {
         if(this.lead != 0)
         {
          fship.setCourse1(course);
         }
         super.setCourse(course);
        }

        //Status of the ship
        public void status()
        {
          double[] a = getPos();
          double b = getSpeed();
          int c = getCourse();
          if(this.follow != 0)
          {
           System.out.println(name + ": " + "Position = (" + (Math.round(100.0 * a[0])/100.0) + ", " + (Math.round(100.0 * a[1])/100.0) + ") following " + lship.name + " (Speed = " + b + " Course = " + c + ") " );
          }
          else
          {
           super.status();
          }
         }
}
