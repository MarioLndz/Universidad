/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

/**
 *
 * @author mario & laura & mario
 */
public class PowerEfficientSpaceStation extends SpaceStation{
    
    private static final float EFFIENCYFACTOR=1.1f;
    
    PowerEfficientSpaceStation(SpaceStation station){
        super(station);
    }
    
    @Override
    public float fire(){
        return super.fire()*EFFIENCYFACTOR;
    }
    
    @Override
    public float protection(){
        return super.protection()*EFFIENCYFACTOR;
    }
    
    
    @Override
    public void setLoot(Loot loot){
        
        
    }
}
