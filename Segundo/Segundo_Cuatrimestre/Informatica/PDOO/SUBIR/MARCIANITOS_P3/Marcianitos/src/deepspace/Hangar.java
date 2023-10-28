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
public class Hangar {
    private int maxElements;
    private ArrayList<ShieldBooster> shieldBoosters; 
    private ArrayList<Weapon> weapons;
    
    Hangar(int capacity){
        this.maxElements = capacity;
        this.shieldBoosters = new ArrayList<ShieldBooster>();
        this.weapons = new ArrayList<Weapon>();
    }
    
    Hangar(Hangar h) {
        this.maxElements = h.maxElements;
        this.shieldBoosters = h.getShieldBoosters();
        this.weapons = h.getWeapons();
    }
    
    HangarToUI getUIversion() {
        return new HangarToUI(this);
    }
    
    private boolean spaceAvailable(){
        return (getMaxElements() > (getShieldBoosters().size() + getWeapons().size()));
    }
    
    public boolean addWeapon(Weapon w) {
        boolean added = false;
        if (spaceAvailable()) {
            getWeapons().add(w);
            added=true;
        }
        return added;
    }
    
    public boolean addShieldBooster(ShieldBooster s) {
        boolean added = false;
        if (spaceAvailable()) {
            getShieldBoosters().add(s);
            added=true;
        }
        return added;
    }
    
    public int getMaxElements() {
        return this.maxElements;
    }
    
    public ArrayList<ShieldBooster> getShieldBoosters(){
        return this.shieldBoosters;
    }
    
    public ArrayList<Weapon> getWeapons() {
        return this.weapons;
    }
    
    public ShieldBooster removeShieldBooster(int s){
        ShieldBooster shield = null;
        if (s < getShieldBoosters().size() && s >= 0) {
            shield = getShieldBoosters().get(s);
            getShieldBoosters().remove(s);
        }
        return shield;
    }
    
    public Weapon removeWeapon(int w){
        Weapon weapon = null;
        if (w < getWeapons().size() && w >= 0) {
            weapon = getWeapons().get(w);
            getWeapons().remove(w);
        }
        return weapon;    
    }
    
}
