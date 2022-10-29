<Qucs Schematic 0.0.19>
<Properties>
  <View=0,-120,1345,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=P3_Ejercicio2.dat>
  <DataDisplay=P3_Ejercicio2.dpl>
  <OpenDisplay=1>
  <Script=P3_Ejercicio2.m>
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
  <C C1 1 520 270 17 -26 0 1 "10 uF" 1 "0 V" 0 "neutral" 0>
  <R R1 1 390 200 -26 15 0 0 "1 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <GND * 1 400 340 0 0 0 0>
  <Vac V1 1 280 290 18 -26 0 1 "10 V" 1 "1 GHz" 0 "0" 0 "0" 0>
  <.AC AC1 1 880 40 0 47 0 0 "log" 1 "0.01 Hz" 1 "10 kHz" 1 "30" 1 "no" 0>
  <Eqn Transferencia 1 900 350 -39 18 0 0 "T=Vo.v/Vi.v" 1 "yes" 0>
  <Eqn Modulo 1 900 480 -39 18 0 0 "Modulo=20*log10(abs(T))" 1 "yes" 0>
  <Eqn Eqn1 1 1180 480 -39 18 0 0 "Argumento=arg(T)" 1 "yes" 0>
  <VProbe Vi 1 140 290 -78 -10 1 3>
  <VProbe Vo 1 680 270 38 -10 0 3>
</Components>
<Wires>
  <280 200 360 200 "" 0 0 0 "">
  <280 200 280 240 "" 0 0 0 "">
  <280 320 280 330 "" 0 0 0 "">
  <520 200 520 240 "" 0 0 0 "">
  <280 340 400 340 "" 0 0 0 "">
  <520 300 520 310 "" 0 0 0 "">
  <400 340 520 340 "" 0 0 0 "">
  <160 280 180 280 "" 0 0 0 "">
  <180 240 180 280 "" 0 0 0 "">
  <280 240 280 260 "" 0 0 0 "">
  <180 240 280 240 "" 0 0 0 "">
  <160 300 180 300 "" 0 0 0 "">
  <180 300 180 330 "" 0 0 0 "">
  <280 330 280 340 "" 0 0 0 "">
  <180 330 280 330 "" 0 0 0 "">
  <420 200 520 200 "" 0 0 0 "">
  <520 240 650 240 "" 0 0 0 "">
  <650 240 650 260 "" 0 0 0 "">
  <650 260 660 260 "" 0 0 0 "">
  <650 280 660 280 "" 0 0 0 "">
  <650 280 650 310 "" 0 0 0 "">
  <520 310 520 340 "" 0 0 0 "">
  <520 310 650 310 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
