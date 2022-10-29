<Qucs Schematic 0.0.19>
<Properties>
  <View=0,-19,1004,763,1.21,0,0>
  <Grid=10,10,1>
  <DataSet=P.1_Ejercicio2.dat>
  <DataDisplay=P.1_Ejercicio2.dpl>
  <OpenDisplay=1>
  <Script=P.1_Ejercicio2.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Título>
  <FrameText1=Dibujado por:>
  <FrameText2=Fecha:>
  <FrameText3=Revisión:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <.DC DC1 1 450 70 0 47 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <VProbe V1 1 230 120 -15 -59 0 0>
  <IProbe I1 1 330 240 -9 -63 0 0>
  <IProbe I2 1 330 400 -9 38 1 0>
  <VProbe V2 1 230 500 -12 37 1 0>
  <R R1 1 230 240 -26 15 0 0 "2.2 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <R R2 1 230 400 -29 -56 1 2 "4.7 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <Eqn Eqn1 1 600 310 -39 18 0 0 "I2_I1=I2.I/I1.I" 1 "yes" 0>
  <Eqn Eqn2 1 600 430 -39 18 0 0 "R2_R1=R2.R/R1.R" 1 "yes" 0>
  <Idc I3 1 250 610 -26 -66 0 2 "10 mA" 1>
</Components>
<Wires>
  <380 320 440 320 "" 0 0 0 "">
  <440 320 440 610 "" 0 0 0 "">
  <140 320 140 400 "" 0 0 0 "">
  <260 400 280 400 "" 0 0 0 "">
  <140 400 180 400 "" 0 0 0 "">
  <180 400 200 400 "" 0 0 0 "">
  <180 400 180 440 "" 0 0 0 "">
  <280 400 280 440 "" 0 0 0 "">
  <140 240 140 320 "" 0 0 0 "">
  <260 240 280 240 "" 0 0 0 "">
  <140 240 180 240 "" 0 0 0 "">
  <180 240 200 240 "" 0 0 0 "">
  <180 200 180 240 "" 0 0 0 "">
  <180 200 220 200 "" 0 0 0 "">
  <220 140 220 200 "" 0 0 0 "">
  <240 140 240 200 "" 0 0 0 "">
  <240 200 280 200 "" 0 0 0 "">
  <280 200 280 240 "" 0 0 0 "">
  <280 240 300 240 "" 0 0 0 "">
  <380 320 380 400 "" 0 0 0 "">
  <360 400 380 400 "" 0 0 0 "">
  <280 400 300 400 "" 0 0 0 "">
  <380 240 380 320 "" 0 0 0 "">
  <360 240 380 240 "" 0 0 0 "">
  <180 440 220 440 "" 0 0 0 "">
  <220 440 220 480 "" 0 0 0 "">
  <240 440 280 440 "" 0 0 0 "">
  <240 440 240 480 "" 0 0 0 "">
  <80 610 220 610 "" 0 0 0 "">
  <80 320 140 320 "" 0 0 0 "">
  <280 610 440 610 "" 0 0 0 "">
  <80 320 80 610 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
