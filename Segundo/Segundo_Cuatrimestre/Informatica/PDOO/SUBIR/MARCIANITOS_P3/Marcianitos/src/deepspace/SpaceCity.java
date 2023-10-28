/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package deepspace;

import java.util.ArrayList;

/**
 *
 * @author mario
 */
public class SpaceCity extends SpaceStation {
	
	private SpaceStation base;
	private ArrayList<SpaceStation> collaborators;
	
	
	public SpaceCity(SpaceStation la_base, ArrayList<SpaceStation> los_collaborators) {
		super(la_base);
		
		this.base = la_base;
		this.collaborators = los_collaborators;
		
	}
	
	public ArrayList<SpaceStation> getCollaborators (){
		return (collaborators);
	}
	
	@Override
	public float fire (){
		float fire = base.fire();
		
		for (int i = 0; i < collaborators.size(); ++i){
			fire += collaborators.get(i).fire();
		}
		
		return (fire);
		
	}
	
	@Override
	public float protection (){
		float protection = base.protection();
		
		for (int i = 0; i < collaborators.size(); ++i){
			protection += collaborators.get(i).protection();
		}
		
		return (protection);
	}
	
	@Override
	public void setLoot (Loot loot) {
		
	}
	
}
