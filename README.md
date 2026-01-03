<h1>KERNEL2 PROJECT</h1>

<h2>Basic Overview</h2>
<h4>A project meant for a deeper dive into kernel development.</h4>
<h4>Purely a mix of the "Barebones" tutorial and the "Meaty Skeleton" tutorial on OSDev Wiki. THis is based on my skills and I don't really have good knowledge of the topic so its quite basic </h4>

<h2>Details</h2>
<ul>
  <li>Used C</li>
  <li>Used GAS assembly for assembler</li>
  <li>Using GRUB for bootloader</li>
  <li>gcc 7.1.0, Binutils 2.28 (Lordmilko repo)</li>
  <li>constant polling for keyboard input(NO SHIFT)</li>
</ul>

<h2>Apps</h2>
<ul>
  <li>Calc: a simple calculator app</li>
  <li>Echo: just echoing stuff</li>
  <li>Helloworld: returns "Hello, World!"</li>
  <li>Man: just a "help" thing. I didn't complete it yet</li>
</ul>

<h2>Requirements</h2>
<ul>
  <li>Any system running i686/x86 architecture (only works on those systems I haven't added ARM support/64bit support)</li>
  <li>a usb (no installing stuff yet) > 1gb</li>
  <li>like 20 mbs of ram I haven't checked yet but optimized for ram shortage these days</li>
  <li>qemu-sysem-i386 (for the shell executable --> run.sh if you're insane enough to want to run it)</li>
</ul>


<h3>comments</h3>
<h4>I'm going to add the specific build files here so I can use multiplatform I'm too lazy to download everything on all my laptops</h4>
<h4>EDIT: I just realized that I don't have to make my own crosscompiler nevermind --> used lordmilko repo for crosscompiler </h4>
<h4>I think I'm done as of 2026/1/3 cuz I want to rewrite the kernel in rust wish me luck</h4>
