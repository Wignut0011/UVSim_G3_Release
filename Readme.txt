<!-- language: lang-none -->
<pre>
 __ __  __ __  __ __       _____ ____  ___ ___  __ __  _       ____  ______   ___   ____  
|  T  T|  T  ||  T  T     / ___/l    j|   T   T|  T  T| T     /    T|      T /   \ |    \ 
|  |  ||  |  ||  |  |    (   \_  |  T | _   _ ||  |  || |    Y  o  ||      |Y     Y|  D  )
|  |  ||  |  ||  |  |     \__  T |  | |  \_/  ||  |  || l___ |     |l_j  l_j|  O  ||    / 
|  :  |l  :  !|  :  |     /  \ | |  | |   |   ||  :  ||     T|  _  |  |  |  |     ||    \ 
l     | \   / l     |     \    | j  l |   |   |l     ||     ||  |  |  |  |  l     !|  .  Y
 \__,_j  \_/   \__,_j      \___j|____jl___j___j \__,_jl_____jl__j__j  l__j   \___/ l__j\_j
                                                                                          

--------------------------------------------------------------------------------------------------
==================================================================================================
--------------------------------------------------------------------------------------------------

	|===================|
	|      TABLE        |
	|===================|
	|1: OVERVIEW        |
	|2: LOAD            |
	|3: EDITING MODE    |
	|4: EXECUTION MODE  |
	|5: INSTRUCTIONS    |
	|___________________|

--------------------------------------------------------------------------------------------------
==================================================================================================
--------------------------------------------------------------------------------------------------
    
 1 |
___|

	OVERVIEW
	========
	
	UVSim is a Command Line based Machine Language Simulator developed as an educational
	tool for the purpose of learning Machine Language. UVSim contains 1 register nammed
	"Accumulator", 15 instructions, and 100 lines of memory. UVSim first opens in a menu.
	The ReadMe, Load Memory, Editing Mode, Execution Mode, and Exit. You can load memory
	modules in the load menu and create then save memory files in Editing Mode and run 
	loaded memory in Execution Mode. In order to start Execution Mode, you need to have a
	staged memory module via loading it or creating it in Editing Mode.
	
--------------------------------------------------------------------------------------------------
==================================================================================================
--------------------------------------------------------------------------------------------------
	
 2 |
___|
	
	LOAD
	====
	
	A list of saved .mem memory modules from the memory folder will be displayed in this
	menu. If no files were saved here, it will be blank. In order to start Execution Mode,
	you need to load a memory module from this menu or a recently create a module from Editing
	Mode.
	
--------------------------------------------------------------------------------------------------
==================================================================================================
--------------------------------------------------------------------------------------------------
	
 3 |
___|

	EDITING MODE
	============
	
	  ________________
	  |UVUSim.exe    |
	  |--------------|
	  | 00 ? +1009   |
          | ...          |
          | 05 ? +3011_< |
            --   ----- 
            ^    ^^ ^
            1    23 4
		
	1: Address
	2: Interger sign
	3: Opcode
	4: Operand
	
	In Editing Mode, you will input your instrucions line by line starting at line 00 as shown 
	above. Each instruction contains an interger sign, opcode, and operand. The sign tells
	the simulator if the data is positive or negative. The opcode tells the simulator what
	instruction to do (a list of each opcode and a discription is listed below). The operand
	is dependent on the opcode, so refer to the instruction list for information on each
	purpose. Since the memory is limited to 100 lines, you will only be	able to input
	instructions until line 99. When you want the program to finish at a particular line, be
	sure to put a HALT instruction. To exit Editing Mode you can either fill all 99 lines
	or input -9999. Doing this will prompt you to either save the memory module as a file or
	not. Either way, this memory will be staged to run in Execution Mode.
		
	Hint: You may want to reserve a block of lines for data, if so, you can use it as pure
	data, or you may want to leave it empty incase you want to save data during execution.
	
	CAUTION: Be aware of the arithmatic you are asking the simulator to perform. Since each
	word is limited to 4 digits, you may experience an overflow or underflow if the arithmatic
	results	in a higher/lower digit number. IE: Once it reaches the limit of +9999, it will
	wrap back to the other limit of -9999 and continue, resulting in a false answer.

--------------------------------------------------------------------------------------------------
==================================================================================================
--------------------------------------------------------------------------------------------------

 4 |
___|

	EXECUTION MODE
	==============
	
	
	In order to start this mode, you need to have a staged memory module. If no memory module
	has been staged, you can't run this mode yet. To have a module staged, you either have to
	create one in Editing Mode or load one.
	
	Once in Execution Mode, the simulator will start to execute the instructions in the staged
	memory module. Depending on your instructions, you may be prompted to input a number during
	it's runtime. Once a HALT instruction has been reached, or line 99 had been executed, 
	Execution Mode will end and a dump of the memory and each register will be printed on the
	screen. Once you are done reviewing the dump, you will be put back into the main menu.
	
--------------------------------------------------------------------------------------------------
==================================================================================================
--------------------------------------------------------------------------------------------------

 5 |
___|
	
	LIST OF INSTRUCTIONS
	====================
	
	
	I/O Instructions:
		READ = 10               Read a word from the keyboard into a specific location in memory.
		WRITE = 11              Write a word from a specific location in memory to screen.
		
	Load/store Instructions:
		LOAD = 20               Load a word from a specific location in memory into the accumulator.
		STORE = 21              Store a word from the accumulator into a specific location in memory. 
		
	Arithmetic Instructions:
		Add = 30                Add a word from a specific location in memory to the word in the
	                                accumulator (leave the result in the accumulator)
		SUBTRACT = 31           Subtract a word from a specific location in memory from the word in the
		                        accumulator (leave the result in the accumulator)
		DIVIDE = 32             Divide the word in the accumulator by a word from a specific location in
		                        memory (leave the result in the accumulator).
		MULTIPLY = 33           multiply a word from a specific location in memory to the word in the
		                        accumulator (leave the result in the accumulator).
		
	Control Instructions:
		BRANCH = 40             Branch to a specific location in memory
		BRANCHNEG = 41          Branch to a specific location in memory if the accumulator is negative. 
		BRANCHZERO = 42         Branch to a specific location in memory if the accumulator is zero.
		HALT = 43               Pause the program
			
	
--------------------------------------------------------------------------------------------------
==================================================================================================
--------------------------------------------------------------------------------------------------
