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

	|==================|
	|     TABLE        |
	|==================|
	|1: Functionality  |
	|                  |
	|2: Requirements   |
	|                  |
	|3: Test Cases     |
	|__________________|

--------------------------------------------------------------------------------------------------
==================================================================================================
--------------------------------------------------------------------------------------------------
    
 1 |
___|

	Operation
	---------
	This simulator is meant to emulate coding in machine language. It will be a Command Line
	based program where the user will input their code as signed 4 digit decimal numbers one
	line at a time then execute the code they had input. Each line will represent memory
	locations. Memory will be limited to 100 lines, thus, lines will be numbered 00-99. When
	the user is finished coding, they will input -99999.

	Specs
	------
	It will contain 1 register nammed "Accumulator" and contain 15 operations. Operations
	not needed for this milestone will be marked as "missing" in this readme. The simulator
	will emulate an ALU. The only operations the ALU will utilize are XOR and AND. An n bit
	full will also be simulated.
	
	
	====================================
	  ________________
	  |UVUSim.exe    |
	  |--------------|
          | ...          |
          | 04 ? +1009   |
          | 05 ? +3011_< |
            --   ----- 
            ^    ^^ ^
            1    23 4
		
	1: Base 10 Address (5 = X0005)
	2: Interger sign
	3: Operator
	4: Operand
	
	====================================
	
	
	I/O operations:
		READ = 10               Read a word from the keyboard into a specific location in memory.
		WRITE = 11              Missing
		
	Load/store operations:
		LOAD = 20               Load a word from a specific location in memory into the accumulator.
		STORE = 21              Missing
		
	Arithmetic operations:
		Add = 30                Add a word from a specific location in memory to the word in the
                                    accumulator (leave the result in the accumulator)
		SUBTRACT = 31           Missing
		DIVIDE = 32             Missing
		MULTIPLY = 33           Missing
		
	Control operations:
		BRANCH = 40             Branch to a specific location in memory
		BRANCHNEG = 41          Missing
		BRANCHZERO = 42         Missing
		HALT = 43               Missing
		
	Debugging operations:
		MEMDUMP	                Print the memory image on the screen.
		BREAK                   Missing
		CONTINUE                Missing
		
	
	
--------------------------------------------------------------------------------------------------
==================================================================================================
--------------------------------------------------------------------------------------------------
	
 2 |
___|

	Milestone 1 will require these to be completed
	==============================================
	
		40 Pts
		------
			1: A working command line prototype
			2: 5 operations (READ, LOAD, ADD, BRANCH, MEMDUMP)
			3: A comment from each team member regarding their part of the implementation
			*Some implementation such as the ALU and debugging may be skipped
			
		20 Pts
		------
			1: A Case Diagram to describe the system to the stakeholders (professor)
			2: 10-15 use cases equally detailed.
			
		15 Pts
		------
			6: One page comparing SCRUM to another process model.
				A: 3 reasons to support and 3 reasons against SCRUM.
				B: 3 reasons to support and 3 reasons against the process model we chose.
		
		10 Pts
		------
			Description decomposing the milestone, backlog, and sprints.
			
		10 Pts
		------
			3 passing test cases (2 will be provided)
			*While testing, a stub may be introduced
			
		5  Pts
		------
			A meeting log with a signiture from each team member.
			*No signature will mark the submission as late.
		
		
--------------------------------------------------------------------------------------------------
==================================================================================================
--------------------------------------------------------------------------------------------------
	
 3 |
___|

	1: (Provided)
	
	2: (Provided)
	
	3: Add 2 numbers together?