/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

/**
 *
 * @author mario & Laura
 */
class ShieldBooster {
    private String name;
    private float boost;
    private int uses;
    
    ShieldBooster (String the_name, float the_boost, int the_uses){
        this.name = the_name;
        this.boost = the_boost;
        this.uses = the_uses;
    }
    
    ShieldBooster (ShieldBooster s){
        this.name = s.name;
        this.boost = s.boost;
        this.uses = s.uses;
    }
    
    ShieldToUI getUIversion() {
        return new ShieldToUI(this);
    }
    
    public float getBoost (){
        return (this.boost);
    }
    
    public int getUses (){
        return (this.uses);
    }
    
    public float useIt(){
        float retorno = 1;
        
        if (this.uses > 0){
            --uses;
            retorno = boost;
        }
        
        return (retorno);
    }
    
    public String toString(){
        
        String salida;
        
        salida = "Name=" + name + ", Boost=" + boost + ", Uses=" + uses;
        
        return salida;
    }
}
