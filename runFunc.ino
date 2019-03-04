String runFunc(int inputFunc, String args) {
  String returnfunc = "";
  int pos = 0;
  String a = "";
  switch(inputFunc) {
    case 1:
      a = getResistance();
      returnfunc = "readResistance" + a + ")";
      return(returnfunc);
    case 2:
      Turner(args,&catcher);
      return("");
    case 3:
      Turner(args,&wheel);
      return(returnfunc);
    case 4:
      pos = args.substring(0,args.indexOf(')')).toInt();
      Grabber.write(pos);
      returnfunc = "ohmArmPosition()";
      return(returnfunc);
    case 5:
      return("error(500)");
  }
}
