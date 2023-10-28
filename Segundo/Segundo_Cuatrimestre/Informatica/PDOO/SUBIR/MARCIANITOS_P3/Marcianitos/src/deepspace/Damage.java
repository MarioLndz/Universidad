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
abstract public class Damage {
    private int nShields;
    //private int nWeapons;
    //private ArrayList<WeaponType> weapons; 
    
    // static final int NO_USO = -1;  no hace falta creo
    
    //creo q este sería el unico constrctor
    Damage (int s) {
        this.nShields = s;
    }
    
    /*
    Damage(int w, int s){
        //this.nWeapons = w;
        this.nShields = s;
       // weapons = null;    creo que ya no hace falta
    }
    
    Damage(ArrayList<WeaponType> wl, int s) {
        //this.weapons = wl;
        this.nShields = s;
        //this.nWeapons = NO_USO; 
    }
    */
    
    // nuevo "constructor de copia"
    abstract public Damage copy();
    
    abstract DamageToUI getUIversion();
    
    int arrayContainsType(ArrayList<Weapon> w, WeaponType t) {        
        int pos = -1;
        boolean encontrado = false;
        int i = 0;
        
        while(i<w.size() && !encontrado) {
            if (w.get(i).getType() == t) {
                encontrado = true;
                pos = i;
            }
            else
                i++;
        }
        
        return pos;
    }
    
    abstract public Damage adjust(ArrayList<Weapon> w, ArrayList<ShieldBooster> s);

    abstract public void discardWeapon(Weapon w);
    
    public void discardShieldBooster() { //funciona
        if (getNShields() > 0)
            this.nShields --;
    }
    
    abstract public boolean hasNoEffect();
    
    public int getNShields() {
        return this.nShields;
    }
    
    public String toString() {
        return ("numero shields: " + nShields + "\n");
    }
}