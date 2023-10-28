package deepspace;

import java.util.ArrayList;

/**
 *
 * @author laura
 */
public class NumericDamage extends Damage{
    private int nWeapons;
    
    NumericDamage (int w, int s){
        super(s);
        this.nWeapons = w;
    }
    
     // "constructor de copia"
    @Override
    public NumericDamage copy() {     // ns si esta bien
        return (new NumericDamage(this.getNWeapons(), this.getNShields()));
    }
    
    @Override
    NumericDamageToUI getUIversion(){
        return new NumericDamageToUI(this);
    }
    
    @Override
    public NumericDamage adjust(ArrayList<Weapon> w, ArrayList<ShieldBooster> s) { 

        int l_nshields = Math.min(s.size(), this.getNShields());
        int l_nweapons = Math.min(w.size(), this.getNWeapons());

        return new NumericDamage(l_nweapons, l_nshields);
    }
    
    @Override
    public void discardWeapon(Weapon w) {   // funciona
        if (getNWeapons() > 0)
            this.nWeapons--;
    }
    
    @Override
    public boolean hasNoEffect(){ 
        return (this.getNWeapons()==0 && this.getNShields()==0);
    }

    public int getNWeapons() {
        return this.nWeapons;
    }
    
    @Override
    public String toString() {
        String out = super.toString();
        out += "numero weapons: " + nWeapons + "\n";
        
        return out;
    }
}