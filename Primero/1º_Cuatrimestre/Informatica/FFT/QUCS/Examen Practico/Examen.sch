<Qucs Schematic 0.0.19>
<Properties>
  <View=0,0,1365,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=Examen.dat>
  <DataDisplay=Examen.dpl>
  <OpenDisplay=1>
  <Script=Examen.m>
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
  <Vac V1 1 260 410 18 -26 0 1 "1 V" 1 "1 GHz" 0 "0" 0 "0" 0>
  <R R1 1 410 320 -26 15 0 0 "5 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <VProbe Vi 1 140 410 -55 -13 1 3>
  <VProbe Vo 1 740 390 39 -10 0 3>
  <L L1 1 410 240 -29 -60 0 0 "25 mH" 1 "0" 0>
  <Eqn T 1 960 430 -39 18 0 0 "T=Vo.v/Vi.v" 1 "yes" 0>
  <Eqn Modulo 1 960 570 -39 18 0 0 "Modulo=20*log10(abs(T))" 1 "yes" 0>
  <Eqn Argumento 1 1200 420 -39 18 0 0 "Argumento=arg(T)" 1 "yes" 0>
  <R R2 1 560 410 15 -26 0 1 "5 kOhm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <.AC AC1 1 900 120 0 47 0 0 "log" 1 "10 Hz" 1 "10 GHz" 1 "50" 1 "no" 0>
</Components>
<Wires>
  <260 280 340 280 "" 0 0 0 "">
  <260 280 260 360 "" 0 0 0 "">
  <440 320 480 320 "" 0 0 0 "">
  <340 280 340 320 "" 0 0 0 "">
  <340 320 380 320 "" 0 0 0 "">
  <480 240 480 280 "" 0 0 0 "">
  <440 240 480 240 "" 0 0 0 "">
  <340 240 340 280 "" 0 0 0 "">
  <340 240 380 240 "" 0 0 0 "">
  <480 280 480 320 "" 0 0 0 "">
  <480 280 560 280 "" 0 0 0 "">
  <560 280 560 300 "" 0 0 0 "">
  <560 440 560 500 "" 0 0 0 "">
  <260 520 560 520 "" 0 0 0 "">
  <260 440 260 460 "" 0 0 0 "">
  <260 360 260 380 "" 0 0 0 "">
  <180 360 260 360 "" 0 0 0 "">
  <180 360 180 400 "" 0 0 0 "">
  <160 400 180 400 "" 0 0 0 "">
  <160 420 180 420 "" 0 0 0 "">
  <180 420 180 460 "" 0 0 0 "">
  <260 460 260 520 "" 0 0 0 "">
  <180 460 260 460 "" 0 0 0 "">
  <560 300 560 380 "" 0 0 0 "">
  <560 300 700 300 "" 0 0 0 "">
  <700 300 700 380 "" 0 0 0 "">
  <700 380 720 380 "" 0 0 0 "">
  <560 500 560 520 "" 0 0 0 "">
  <560 500 700 500 "" 0 0 0 "">
  <700 400 700 500 "" 0 0 0 "">
  <700 400 720 400 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
