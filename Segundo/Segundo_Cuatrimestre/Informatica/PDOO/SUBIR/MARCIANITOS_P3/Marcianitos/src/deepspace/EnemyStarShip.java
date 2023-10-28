/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

/**
 *
 * @author laura
 */
public class EnemyStarShip {    // funciona
    private float ammoPower;
    private String name;
    private float shieldPower;
    private Loot loot;
    private Damage damage;
    
    EnemyStarShip(String n, float a, float s, Loot l, Damage d) {
        this.name = n;
        this.ammoPower = a;
        this.shieldPower = s;
        this.loot = l;
        this.damage = d;
    }
    
    EnemyStarShip(EnemyStarShip e) {
        this.name = e.name;
        this.ammoPower = e.ammoPower;
        this.shieldPower = e.shieldPower;
        this.loot = e.loot;
        this.damage = e.damage;
    }
    
    EnemyToUI getUIversion() {
        return new EnemyToUI(this);
    }
    
    public float fire(){
        return this.getAmmoPower();
    }
    
    public float getAmmoPower(){
        return this.ammoPower;
    }
    
    public Damage getDamage(){
        return this.damage;
    }
    
    public Loot getLoot(){
        return this.loot;
    }
    
    public String getName(){
        return this.name;
    }
    
    public float getShieldPower(){
        return this.shieldPower;
    }
    
    public float protection(){
        return this.getShieldPower();
    }
    
    public ShotResult receiveShot(float shot){
        ShotResult resultado;
        
        if (protection() < shot)
            resultado = ShotResult.DONOTRESIST;
        else
            resultado = ShotResult.RESIST;
       
        return resultado;           
    }
}
