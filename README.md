# Chicken Esolang Interpreter

Chicken is an esoteric language by Torbjörn Söderstedt which consists of only three tokens: "chicken", " " and "\n". The number of chickens corresponds to an opcode. Trailing newlines are significant, as an empty line will produce a "0" opcode. This language supports the following instruction
<table class="wikitable">
<tbody><tr>
<th>Opcode
</th>
<th>Name
</th>
<th>Name (chicken)
</th>
<th>Description
</th></tr>
<tr>
<td><code>0</code>
</td>
<td>exit
</td>
<td>axe
</td>
<td>Stop execution.
</td></tr>
<tr>
<td><code>1</code>
</td>
<td>chicken
</td>
<td>chicken
</td>
<td>Push the string "chicken" onto the stack.
</td></tr>
<tr>
<td><code>2</code>
</td>
<td>add
</td>
<td>add
</td>
<td>Add two top stack values.
</td></tr>
<tr>
<td><code>3</code>
</td>
<td>subtract
</td>
<td>fox
</td>
<td>Subtract two top stack values.
</td></tr>
<tr>
<td><code>4</code>
</td>
<td>multiply
</td>
<td>rooster
</td>
<td>Multiply two top stack values.
</td></tr>
<tr>
<td><code>5</code>
</td>
<td>compare
</td>
<td>compare
</td>
<td>Compare two top stack values for equality, push truthy or falsy result onto the stack.
</td></tr>
<tr>
<td><code>6</code>
</td>
<td>load
</td>
<td>pick
</td>
<td>Double wide instruction. Next instruction indicates source to load from. 0 loads from stack, 1 loads from user input. Top of stack points to address/index to load onto stack.
</td></tr>
<tr>
<td><code>7</code>
</td>
<td>store
</td>
<td>peck
</td>
<td>Top of stack points to address/index to store to. The value below that will be popped and stored.
</td></tr>
<tr>
<td><code>8</code>
</td>
<td>jump
</td>
<td>fr
</td>
<td>Top of stack is a relative offset to jump to. The value below that is the condition. Jump only happens if condition is truthy.
</td></tr>
<tr>
<td><code>9</code>
</td>
<td>char
</td>
<td>BBQ
</td>
<td>Interprets the top of the stack as ascii and pushes the corresponding character.
</td></tr>
<tr>
<td><code>10+</code>
</td>
<td>push
</td>
<td>
</td>
<td>Pushes the literal number n-10 onto the stack.
</td></tr></tbody></table>

<br/>


## Usage

To use this interpreter simply compile the cpp files without any external libraries. A makefile is attached for convinience. The executable takes two command line argument: first one is the path to input program and second one is the user input.

```bash
make
./chicken progs/99chickens.chic 9
```

## References

This repository is inspired from the following function

```javascript
function chicken(CHICKEN, Chicken) {
    Chicken &&( chicken. chicken =[,
    CHICKEN, CHICKEN = Chicken = chicken.
    $Chicken =-( CHICKEN ==( chicken.
    Chicken = Chicken ))], chicken.
    chicken [Chicken++] = chicken. chicken, chicken.
    CHICKEN = ++Chicken, chicken (--Chicken), chicken.
    $Chicken = ++Chicken, chicken. CHICKEN++ );
    Chicken = chicken. Chicken [chicken.
    $Chicken++ ]; chicken. Chicken = CHICKEN? Chicken?
    '\012'== Chicken? chicken (++ CHICKEN, chicken.
    chicken [++ chicken. CHICKEN ]=
    CHICKEN - CHICKEN ): Chicken
    ==' '|'\015'== Chicken ||
    (Chicken   )== "c" &  chicken. Chicken [chicken.
    $Chicken++ ]== "h" &  chicken. Chicken [chicken.
    $Chicken++ ]== "i" &  chicken. Chicken [chicken.
    $Chicken++ ]== "c" &  chicken. Chicken [chicken.
    $Chicken++ ]== "k" &  chicken. Chicken [chicken.
    $Chicken++ ]== "e" &  chicken. Chicken [chicken.
    $Chicken++ ]== "n"&&++chicken. chicken [chicken.
    CHICKEN]? chicken (CHICKEN)
    :[ "Error on line "+CHICKEN+": expected 'chicken'",
       chicken. CHICKEN = CHICKEN ++- CHICKEN ]:
    chicken. chicken :( CHICKEN = chicken.
    Chicken[chicken.CHICKEN], Chicken? (Chicken =

    --Chicken? --Chicken? --Chicken? --Chicken? --Chicken?
    --Chicken? --Chicken? --Chicken? --Chicken?
    chicken. CHICKEN++ &&
    --Chicken :'&#'+CHICKEN+';': chicken.
    Chicken [chicken. Chicken [-- chicken. CHICKEN ]&&
    (chicken. $Chicken += CHICKEN), --chicken.
    CHICKEN ]: chicken. Chicken [chicken.
    Chicken [CHICKEN] = chicken. Chicken
    [-- chicken. CHICKEN ],-- chicken. CHICKEN ]:
    chicken. Chicken [chicken. Chicken [chicken.
    $Chicken++ ]] [CHICKEN]: CHICKEN == chicken.
    Chicken [-- chicken. CHICKEN ]:
    CHICKEN*chicken. Chicken [-- chicken.
    CHICKEN ]: chicken. Chicken [-- chicken.
    CHICKEN ]- CHICKEN: chicken. Chicken [-- chicken.
    CHICKEN ]+ CHICKEN: chicken.
    CHICKEN ++ && "chicken", chicken.
    Chicken [chicken. CHICKEN ]= Chicken, chicken
    ()): CHICKEN );

    return chicken.
    Chicken
}
```
<br/>
For more details take a look at the original publication <a href="http://web.archive.org/web/20180420010853/http://isotropic.org/papers/chicken.pdf">here</a>.