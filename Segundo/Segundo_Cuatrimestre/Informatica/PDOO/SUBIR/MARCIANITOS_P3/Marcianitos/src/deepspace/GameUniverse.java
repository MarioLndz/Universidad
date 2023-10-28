/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

import java.util.ArrayList;

/**
 *
 * @author laura
 */
public class GameUniverse {
    static private int WIN = 10;
    
    private int currentStationIndex;
    private int turns;
    
    private GameStateController gameState;
    private EnemyStarShip currentEnemy;
    private Dice dice;
    private SpaceStation currentStation;
    private ArrayList<SpaceStation> spaceStations;
    
    public GameUniverse(){
        // crear contador de estados de juego
        this.gameState = new GameStateController();
        
        // contador de turno a 0
        this.turns = 0;
        
        // crear dado
        this.dice = new Dice();
        
        currentStationIndex=0;
        currentEnemy=null;
        currentStation=null;
        spaceStations = new ArrayList<SpaceStation>();
    }
    
    CombatResult combat(SpaceStation station, EnemyStarShip enemy) {
        boolean enemyWins;
        GameCharacter ch = dice.firstShot();
        CombatResult resultado;

        if (ch == GameCharacter.ENEMYSTARSHIP){	// Ataca enemigo primero
                float fire = enemy.fire();

                ShotResult result = station.receiveShot(fire);

                if (result == ShotResult.RESIST){
                        fire = station.fire();
                        result = enemy.receiveShot(fire);

                        enemyWins = (result == ShotResult.RESIST);
                } else {
                        enemyWins = true;
                }

        } else {	// Ataca jugador primero
                float fire = station.fire();
                ShotResult result = enemy.receiveShot(fire);

                enemyWins = (result == ShotResult.RESIST);
        }


        if (enemyWins){
                float s = station.getSpeed();

                boolean moves = dice.spaceStationMoves(s);

                if (!moves){
                        Damage damage = enemy.getDamage();
                        station.setPendingDamage(damage);

                        resultado = CombatResult.ENEMYWINS;

                } else {
                        station.move();
                        resultado = CombatResult.STATIONESCAPES;
                }

        } else {
                Loot aLoot = enemy.getLoot();
                station.setLoot(aLoot);
				
				//TODO: TRANSFORMACIONES
				if (aLoot.getEfficient() || aLoot.spaceCity()){
					resultado = CombatResult.STATIONWINSANDCONVERTS;
				} else {
					resultado = CombatResult.STATIONWINS;
				}
				
                

        }

        gameState.next(turns, spaceStations.size());
		
        return (resultado);
    }

    public CombatResult combat() {
        CombatResult resultado = CombatResult.NOCOMBAT;
		
        GameState state = gameState.getState();

        if ((state == GameState.BEFORECOMBAT) || state == GameState.INIT) {		// Combate permitido
                resultado = combat(currentStation, currentEnemy);
        }

        return (resultado);
    }
    
    public void discardHangar() {
        if (this.getState() == GameState.INIT || this.getState() == GameState.AFTERCOMBAT)
            this.currentStation.discardHangar();
    }
    
    public void discardShieldBooster(int i){
        if (this.getState() == GameState.INIT || this.getState() == GameState.AFTERCOMBAT)
            this.currentStation.discardShieldBooster(i);
    }
    
    public void discardShieldBoosterInHangar(int i){
        if (this.getState() == GameState.INIT || this.getState() == GameState.AFTERCOMBAT)
            this.currentStation.discardShieldBoosterInHangar(i);
    }
    
    public void discardWeapon(int i){
        if (this.getState() == GameState.INIT || this.getState() == GameState.AFTERCOMBAT)
            this.currentStation.discardWeapon(i);
    }
    
    public void discardWeaponInHangar(int i){
        if (this.getState() == GameState.INIT || this.getState() == GameState.AFTERCOMBAT)
            this.currentStation.discardWeaponInHangar(i);
    }
    
    public GameState getState() {
        return this.gameState.getState();
    }
    
    public GameUniverseToUI getUIversion() {
        return new GameUniverseToUI(this.currentStation, this.currentEnemy);
    }
    
    public boolean haveAWinner(){
        return (this.currentStation.getNMedals() >= WIN);
    }
    
    public void init(ArrayList<String> names) {
        
        GameState state = gameState.getState();
        
        if(state == GameState.CANNOTPLAY){
            
            CardDealer dealer = CardDealer.getInstance();
            
            for(int i=0;i<names.size();i++){
                
                SuppliesPackage supplies = dealer.suppliesPackages.next();
                
                SpaceStation station = new SpaceStation(names.get(i),supplies);
                
                spaceStations.add(station);
                
                int nh = dice.initWithNHangars();
                
                int nw = dice.initWithNWeapons();
                
                int ns = dice.initWithNShields();
                
                Loot lo = new Loot(0, nw, ns, nh, 0);
                
                station.setLoot(lo);
                                   
            }
            
            currentStationIndex = dice.whoStarts(names.size());
            
            currentStation = spaceStations.get(currentStationIndex);
            
            currentEnemy = dealer.nextEnemy();
            
            gameState.next(turns, spaceStations.size());            
        }      
    }
    
    public void mountShieldBooster(int i){
        if (this.getState() == GameState.INIT || this.getState() == GameState.AFTERCOMBAT)
            this.currentStation.mountShieldBooster(i);
    }
    
    public void mountWeapon(int i) {
        if (this.getState() == GameState.INIT || this.getState() == GameState.AFTERCOMBAT)
            this.currentStation.mountWeapon(i);
    }
    
    public boolean nextTurn() {
        boolean ret = false;
        GameState state = gameState.getState();
        
        if(state == GameState.AFTERCOMBAT) {
            boolean stationState = currentStation.validState();
            
            if(stationState) {
                currentStationIndex = (currentStationIndex+1) % spaceStations.size();
                turns++;
                currentStation = spaceStations.get(currentStationIndex);
                currentStation.cleanUpMountedItems();
                CardDealer dealer = CardDealer.getInstance();
                currentEnemy = dealer.nextEnemy();
                gameState.next(turns, spaceStations.size());
                ret = true;
            }
        }
        return ret;
    }
    
    private void makeStationefficient(){
        
        if(dice.extraEfficiency()){
            
            
        }
    }
}
