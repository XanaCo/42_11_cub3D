<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/cub3dm.png alt=Xanaco's 42Project Badge/>
<h2>Final score</h2>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/125Grade.png alt=Xanaco's 42Project Score/>
<h4>Completed + Bonus</h4>
<h5>Outstanding Project 3/3</h5>
</div>

This is a group project, made with <3 with [@albibou](https://github.com/albibou)

All graphics are made by us. Pixel art characters and end animation by awesome [Gwendal Uguen](https://www.flickr.com/photos/gwendalcentrifugue)

---

## Installation

### Prerequisites
Make sure all dependencies are installed on your system, may vary depending on your distribution.

### Build
```
git clone git@github.com:XanaCo/42_11_cub3D.git Cub3D
cd Cub3D
make && make bonus
```

### Run
For the mandatory part:
```
./cub3D  maps/mandatory/valid/choose-one-file-here
```
For the bonus part:
```
./cub3D_bonus maps/bonus/valid/choose-one-file-here
```

# CUB3D (mini) Bible

<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_StartScreen.png alt=CUB3D Title Screenshot/>
</div>

This project is a school exercise at 42 Paris, designed as a simple raycaster to practice C programming.  
It transformed into a prototype game inspired by retro FPS such as *Wolfenstein 3D*, adding mechanics, a narrative, and interactive elements.  

As a school project, several features remain basic or unfinished, and there is room for refinement and expansion.  
The purpose of this document is to present the core concept and mechanics, while acknowledging that further polish (marked with `*`) would be necessary for a more complete version.  

---

## Table of Contents
- [Project Scope (mandatory vs bonus)](#project-scope-mandatory-vs-bonus)
- [Concept](#concept)
- [Gameplay Loop](#gameplay-loop)
- [Controls](#controls)
- [End Game](#end-game)
- [Playable Character](#playable-character)
- [Story](#story)
- [Actors (NPCs & Environment)](#actors-npcs--environment)
  - [The Overlook Hotel](#the-overlook-hotel-environmentantagonist)
  - [Danny Torrance](#danny-torrance-pursuer)
  - [The Grady Twins](#the-grady-twins-controllers)
- [Areas](#areas)
- [Gamefeel & Feedback](#gamefeel--feedback)
- [Objectives & Aesthetics (MDA)](#objectives--aesthetics-mda)


---

## Project Scope (mandatory vs bonus)

<div align="center" style="display: flex; justify-content: center; gap: 20px;">
  <figure style="text-align: center;">
    <img src="https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_Mandatory.png" alt="Area1" width="45%">
  </figure>

  <figure style="text-align: center;">
    <img src="https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_Bonus.png" alt="Area2" width="45%">
  </figure>
</div>


---

## Concept
A retro FPS inspired by *Wolfenstein 3D*, set in the universe of *The Shining*.  

The player takes control of **Jack Torrance**, navigating the haunted Overlook Hotel in search of the mysterious **Room 237**. Armed with an axe, Jack must break through doors, evade hostile characters, and survive the labyrinthine corridors before time runs out.

- **Genre:** Retro FPS / Exploration / Puzzle-Horror  
- **Target Platform:** Linux (prototype)  
- **Target Audience:** Players who enjoy horror, exploration, and puzzle-infused FPS experiences.
 

<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_Jack.png alt=Screenshot width=60%/>
</div>

> *“I wonder where the room 237 is?”*

---

## Gameplay Loop
1. Explore the Overlook Hotel maze.  
2. Break doors with the axe to progress.  
3. Avoid or escape NPCs who hinder movement.  
4. Find the final Room 237 door before being caught.  

<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_Explore.png alt=Screenshot1 width=30%/>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_TwinsAnim.png alt=Screenshot2 width=30%/>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_Porte237.png alt=Screenshot3 width=30%/>
</div>

---

## Controls
- **Movement:** `WASD` / Arrow keys  
- **Look/Turn:** Mouse  
- **Axe:**  
  - `1` → Equip axe  
  - `2` → Holster axe  
  - `SPACE` → Swing axe  
- **End Game:**  
  - `ESC` or `Q` → Quit game and free memory  

A small reminder screen will appear on launch in terminal, displaying title and controls.

<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_Porte1.png alt=Screenshot4 width=30%/>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_Porte2.png alt=Screenshot5 width=30%/>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_Porte3.png alt=Screenshot6 width=30%/>
</div>

> You can break the doors with the axe and see through.  

---

## End Game
- **User Abort:** Player quits manually (`ESC` / `Q` / Window). Game exits and cleans memory.  
- **Victory:** Player reaches **Room 237** and triggers pixel-art animation ending.  

<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_EndGame.png alt=EndGameScreenshot width=75%/>
</div>

---

## Playable Character
**John Daniel Edward "Jack" Torrance**  
- **Age:** 42  
- **Height/Weight:** 5’9.5” / 154 lbs  
- **Appearance:** Muscular, attractive, but with disturbingly intense eyes.  
- **Backstory:** A failed writer and ex-teacher, burdened by financial struggles, alcoholism, and family pressures. Now trapped in the Overlook, he descends into madness.  
- **Ability:** Can destroy doors with his axe to progress.  

---

## Story
You play as Jack Torrance, attempting to escape the Overlook Hotel by finding the legendary **Room 237**.  
Armed only with an axe, you must demolish doors under time pressure, while avoiding supernatural forces and family members who try to stop you.  

---

## Actors (NPCs & Environment)

### The Overlook Hotel (Environment/Antagonist) `*`
- Built in 1907, cursed by decades of murders and suicides.  
- Acts as an **active enemy**: shifting corridors, closing doors, and supernatural manifestations that block Jack’s path.  

### Danny Torrance (Pursuer)
- A 5-year-old with overwhelming psychic powers (*“the Shining”*).  
- If Danny spots you, he will relentlessly follow, slowing your progress and increasing tension.  

### The Grady Twins (Controllers)
- Ghostly twin girls appearing suddenly in corridors.  
- If they catch you, Jack becomes frozen in place for a few seconds, vulnerable to other threats.  

<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_Overlook.png alt=Actor1 width=30%/>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_DannyT.png alt=Actor2 width=30%/>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_Twins.png alt=Actor3 width=30%/>
</div>

---

## Areas
- **Overlook Ground Floor (Labyrinth):** Maze-like hallways, locked doors, flickering lights.  
- **Typical Room:** An extra zone to explore.

<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_OverlookGF.png alt=Area1 width=45%/>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_TypicalRoom.png alt=Area2 width=45%/>
</div>

---

## Gamefeel & Feedback `*`
- **Axe:** Heavy sound on swing/impact, screen shake, splinters when breaking doors.  
- **Enemies:**  
  - Danny’s psychic whispers intensify as he approaches.  
  - The twins trigger a chilling freeze-frame effect with echoing laughter.  
- **Environment:**  
  - Distant screams, flickering lights, doors slamming shut.  
  - Subtle heartbeat sound when health is low.  

---

## Objectives & Aesthetics (MDA)
- **Mechanics:** Door destruction, NPC avoidance, timed escape.  
- **Dynamics:** Resource pressure (time), stealth vs. confrontation, escalating tension.  
- **Aesthetics:**  
  - **Horror:** constant paranoia, hotel as an enemy.  
  - **Challenge:** navigating maze + time pressure.  
  - **Discovery:** exploration of iconic spaces.  
  - **Sensation:** fear, urgency, thrill of destruction.  

<div align=center>
<img src=https://github.com/Xanaco/42_00_Ressources/blob/main/screenshots/Cub3D_EasterEgg.png alt=MDA width=75%/>
</div>

---
