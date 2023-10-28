/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

import java.util.Random;

/**
 *
 * @author mario & Laura & mario
 */
class Dice {
    private final float NHANGARSPROB;
    private final float NSHIELDSPROB;
    private final float NWEAPONSPROB;
    private final float FIRSTSHOTPROB;
    private static final float EXTRAEFFIENCYPROB=0.8f;
    
    private Random generator;
    
    Dice (){
        this.NHANGARSPROB = 0.25f;
        this.NSHIELDSPROB = 0.25f;
        this.NWEAPONSPROB = 0.33f;
        this.FIRSTSHOTPROB = 0.5f;
        
        this.generator = new Random();
    }
    
    int initWithNHangars (){
        int retorno = 1;
        
        if (this.generator.nextFloat() < NHANGARSPROB){
            retorno = 0;
        }
        
        return (retorno);
    }
    
    int initWithNWeapons (){
        int retorno = 3;
        
        float num = this.generator.nextFloat();
        
        if (num < NWEAPONSPROB){
            retorno = 1;
            
        } else if (num < 2*NWEAPONSPROB){
            retorno = 2;
        }
        
        return (retorno);
    }    
    
    int initWithNShields (){
        int retorno = 1;
        
        float num = this.generator.nextFloat();
        
        if (num < NSHIELDSPROB){
            retorno = 0;
            
        }
        
        return (retorno);
    }
    
    int whoStarts (int nPlayers) {
        return  (this.generator.nextInt(nPlayers));
    }
    
    GameCharacter firstShot () {
        GameCharacter retorno = GameCharacter.ENEMYSTARSHIP;
        
        float num = this.generator.nextFloat();

        if (num < FIRSTSHOTPROB){
            retorno = GameCharacter.SPACESTATION;
        }
        
        return (retorno);
    }
    
    boolean spaceStationMoves (float speed) {
        boolean retorno = false;
        
        float num = this.generator.nextFloat();

        if (num < speed){
            retorno = true;
        }
        
        return (retorno);
    }
    
    public boolean extraEfficiency(){   // en caso de devolver true se hará la extraefficiency
        
        float num = this.generator.nextFloat();
        boolean retorno = (num > EXTRAEFFIENCYPROB);  // para que se true en caso de que haya que hacerlo
        return retorno;
        
    } 
    
    public String toString(){
        
        String salida;
        
        salida = "NHANGARSPROB=" + NHANGARSPROB + ", NSHIELDSPROB=" + NSHIELDSPROB 
                + ", NWEAPONSPROB=" + NWEAPONSPROB + ", FIRSTSHOTPROB=" + FIRSTSHOTPROB;

        return salida;
    }
    
    
    
    

}
