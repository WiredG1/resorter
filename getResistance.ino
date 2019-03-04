String getResistance(){  
      float in = _read(OneKPin);
      if(in > 0.8){       
        return("(1," + String(in));
      } else {
        in = _read(TenKPin);
        if(in > 0.8){
        return("(2," + String(in));
        } else {
          in = _read(HunKPin);
          if(in > 0.8){
            return("(3," + String(in));
          } else {
            in = _read(MilKPin);   
            return("(4," + String(in));
          }
        }
      }
}
