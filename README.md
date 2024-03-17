# SimulatedAnnealingAlgorithm

# Simulated Annealing for the Knapsack Problem

1. ### Introduction
   - **Probabilistic Technique**: Simulated Annealing (SA) employs a probabilistic approach to approximate the global optimum of a function.
   - **Optimization in Large Spaces**: It is particularly suited for optimization problems characterized by large search spaces and multiple local optima.
   - **Metaheuristic Origin**: The technique is inspired by the metallurgical process of annealing, which involves heating and controlled cooling to improve material properties.
   - **Applicability**: SA is favored in scenarios where the search space is discrete, and obtaining a near-optimal global solution is more important than identifying an exact local optimum quickly.
   - **Versatility Across Domains**: Its utility is proven in various fields, including solutions for the traveling salesman problem and job-shop scheduling, underscoring its ability to tackle complex optimization issues.
   - **Alternative to Exact Algorithms**: SA provides an effective alternative in situations where exact algorithms may fail or be impractical, by offering viable approximate solutions.

---

2. ### Pseudocode

![Image.tiff](https://res.craft.do/user/full/3bfd881b-e0e8-70e3-7a1b-80e785e33da2/doc/287F3647-C51E-4910-B8B6-72A03363C403/33D3DDEE-445C-40FA-B72D-C76DA046DE86_2/ibknBLqLHBlILo5BYqcb2qxF5DxiWxRPcFyrhkGaYh8z/Image.tiff)

---

3. ### Result and Discover
   - Best Value: 405349

![output_4.png](https://res.craft.do/user/full/3bfd881b-e0e8-70e3-7a1b-80e785e33da2/doc/287F3647-C51E-4910-B8B6-72A03363C403/D02ED617-3D17-461B-966E-B9111E250129_2/Pymoz3vpKjVbWmY9HV6bPIUoVvqGpNeDCCp4AFqaC3Uz/output_4.png)

   - Because using Simulated Annealing, the acceptance probability is higher at the first, and lower in the end.

![output_6.png](https://res.craft.do/user/full/3bfd881b-e0e8-70e3-7a1b-80e785e33da2/doc/287F3647-C51E-4910-B8B6-72A03363C403/72B08D6E-226C-4FA8-878F-976DE2C8FD3E_2/OH2EYJpNoqxCyaQRjzAOtcugF5hCfQJHmxPDvDFg0ZMz/output_6.png)

   - As the result, the value is changeable at the first and stable in the end. The figure is the experiment under temperature=1000 and cooling rate=0.0005 for 25 times.

![output.png](https://res.craft.do/user/full/3bfd881b-e0e8-70e3-7a1b-80e785e33da2/doc/287F3647-C51E-4910-B8B6-72A03363C403/EC69A36A-115A-4464-9C79-6EB19D9D442E_2/NI05NWvyDzeaV8LDj8mp3t7Ky7eFsWYQj0Z9pLpVq9Az/output.png)

   - The error bar under different cooling rate. The standard deviation is smaller when cooling rate smaller.

![output_7.png](https://res.craft.do/user/full/3bfd881b-e0e8-70e3-7a1b-80e785e33da2/doc/287F3647-C51E-4910-B8B6-72A03363C403/07694261-6D61-4933-9218-874EF52EF47D_2/9bNqFg3NovTewOIytPnxTsxdbc1RlrejlW4EDO6rNXoz/output_7.png)

   - The item which have larger density be selected frequently.

![output_10\.png](https://res.craft.do/user/full/3bfd881b-e0e8-70e3-7a1b-80e785e33da2/doc/287F3647-C51E-4910-B8B6-72A03363C403/C71CA9CE-BF0F-43F6-A9F6-5D953AD7FC7F_2/tqUk5Sphin4WYGlJmRBrcyas8H4q9xGmVeCEDxjRUDUz/output_10.png)

---

4. ### Reference

[Overleaf, Online LaTeX Editor](https://www.overleaf.com/read/kgcmkzqppkjm#91957a)

[Simulated annealing - Wikipedia](https://en.wikipedia.org/wiki/Simulated_annealing)

[【数之道17】金属冷却处理中隐藏的智慧-模拟退火优化算法](https://www.youtube.com/watch?v=P4p-YgidpZ4)

[Wustl](https://www.math.wustl.edu/~feres/Math350Fall2012/Projects/mathproj09.pdf)

