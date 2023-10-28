/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

/**
 *
 * @author mario
 */
class SuppliesPackage {
    private float ammoPower;
    private float fuelUnits;
    private float shieldPower;
    
    SuppliesPackage (float the_ammoPower, float the_fuelUnits, float the_shieldPower){
        this.ammoPower = the_ammoPower;
        this.fuelUnits = the_fuelUnits;
        this.shieldPower = the_shieldPower;
    }
    
    SuppliesPackage (SuppliesPackage s){
        this.ammoPower = s.ammoPower;
        this.fuelUnits = s.fuelUnits;
        this.shieldPower = s.shieldPower;
    }
    
    public float getAmmoPower (){
        return (this.ammoPower);
    }
    
    public float getfuelUnits (){
        return (this.fuelUnits);
    }
    
    public float getshieldPower (){
        return (this.shieldPower);
    }
    
    public String toString(){
        
        String salida;
        
        salida="AmmoPower= " + ammoPower + ", fuelUnits=" + fuelUnits + ", shieldPower" + shieldPower;
        
        return salida;
    }
    
}
