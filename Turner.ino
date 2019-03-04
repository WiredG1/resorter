void Turner(String args,AccelStepper* motor){
      unsigned int o = multibleIndexOf(args, ',');
      String* splittet = split(args, ',', o);

      String arg0 = splittet[0];
      String arg1 = splittet[1];
      String arg2 = splittet[2];

      
      motor->setMaxSpeed(arg1.toInt());
      motor->setAcceleration(arg2.toInt());
      motor->move(arg0.toInt());

      if(motor == &catcher){
        catcherRunning = true;
      } else {
        wheelRunning = true;
      }
}

