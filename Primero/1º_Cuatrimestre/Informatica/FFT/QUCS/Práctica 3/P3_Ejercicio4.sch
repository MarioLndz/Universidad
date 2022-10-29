<Qucs Schematic 0.0.19>
<Properties>
  <View=0,0,1385,800,1,0,0>
  <Grid=10,10,1>
  <DataSet=P3_Ejercicio4.dat>
  <DataDisplay=P3_Ejercicio4.dpl>
  <OpenDisplay=1>
  <Script=P3_Ejercicio4.m>
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
  <C C1 1 410 400 -44 -67 0 0 "970 nF" 1 "" 0 "neutral" 0>
  <L L1 1 530 400 -36 -57 0 0 "26.1 mH" 1 "" 0>
  <R R1 1 600 470 15 -26 0 1 "82 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <Vac V1 1 340 510 -86 -24 0 1 "10 V" 1 "1 GHz" 0 "0" 0 "0" 0>
  <Eqn Transferencia1 1 930 130 -39 18 0 0 "T=Vo.v/Vi.v" 1 "yes" 0>
  <Eqn Modulo1 1 940 250 -39 18 0 0 "Modulo=20*log10(abs(T))" 1 "yes" 0>
  <Eqn Eqn1 1 1200 130 -39 18 0 0 "Argumento=arg(T)" 1 "yes" 0>
  <VProbe Vi 1 180 510 -31 28 1 3>
  <VProbe Vo 1 410 280 28 -31 0 0>
  <.AC AC1 1 130 70 0 47 0 0 "log" 1 "10 Hz" 1 "10 kHz" 1 "50" 1 "no" 0>
</Components>
<Wires>
  <440 400 460 400 "" 0 0 0 "">
  <560 400 600 400 "" 0 0 0 "">
  <600 400 600 440 "" 0 0 0 "">
  <600 500 600 580 "" 0 0 0 "">
  <340 580 600 580 "" 0 0 0 "">
  <340 540 340 560 "" 0 0 0 "">
  <340 400 360 400 "" 0 0 0 "">
  <340 400 340 460 "" 0 0 0 "">
  <200 500 220 500 "" 0 0 0 "">
  <220 460 220 500 "" 0 0 0 "">
  <340 460 340 480 "" 0 0 0 "">
  <220 460 340 460 "" 0 0 0 "">
  <340 560 340 580 "" 0 0 0 "">
  <220 560 340 560 "" 0 0 0 "">
  <220 520 220 560 "" 0 0 0 "">
  <200 520 220 520 "" 0 0 0 "">
  <460 400 500 400 "" 0 0 0 "">
  <460 300 460 400 "" 0 0 0 "">
  <420 300 460 300 "" 0 0 0 "">
  <360 400 380 400 "" 0 0 0 "">
  <360 300 360 400 "" 0 0 0 "">
  <360 300 400 300 "" 0 0 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
