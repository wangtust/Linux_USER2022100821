# 处理机调度与死锁
## 调度
在操作系统中，调度是指操作系统决定哪个进程或线程应该获得处理器资源的过程。这是操作系统进行资源管理的重要部分，尤其是在多任务系统中，多个进程或线程可能会同时请求 CPU。

调度的目标通常包括：

- 公平性：确保每个进程或线程都能获得其公平份额的 CPU 时间。
- 效率：最大化 CPU 的利用率，避免 CPU 空闲。
- 响应时间：对于交互式任务，尽可能减少用户的等待时间。
- 吞吐量：对于批处理任务，尽可能多地完成任务。

操作系统使用调度算法来决定下一个要运行的进程或线程。常见的调度算法包括先来先服务（FCFS）、短作业优先（SJF）、优先级调度、轮转调度（RR）等。
## 调度算法
以下是一些常见的进程调度算法：

1. **先来先服务（FCFS，First-Come, First-Served）**：这是最简单的调度算法。在这种算法中，CPU 按照进程到达的顺序进行分配。先到达的进程先获得 CPU。

2. **短作业优先（SJF，Shortest Job First）**：在这种算法中，CPU 优先分配给预计运行时间最短的进程。这种算法可以最小化平均等待时间，但需要预知进程的运行时间。

3. **优先级调度**：在这种算法中，每个进程都有一个优先级，CPU 优先分配给优先级最高的进程。优先级可以根据各种因素确定，如进程类型、进程等待时间等。

4. **轮转调度（RR，Round Robin）**：在这种算法中，每个进程都被分配一个固定大小的时间片，进程在其时间片内运行。如果进程在其时间片结束时还没有完成，它将被移回队列的末尾，等待下一轮的时间片。

5. **多级反馈队列（Multilevel Feedback Queue）**：这是一种复杂的调度算法，它将进程分为多个队列，每个队列有不同的优先级。进程可以在队列之间移动，以反映其行为和需求的变化。

每种调度算法都有其优点和缺点，适用于不同的场景。操作系统可能会根据系统的需求和状态，动态地选择或切换调度算法。
## 处理机调度层次
处理机调度通常分为三个层次：

1. **高级调度（也称为长程调度或接纳调度）**：这个层次的调度决定哪些进程可以被接纳到就绪队列中，即哪些进程可以被允许进入内存开始运行。这个调度主要发生在多道批处理系统中，其目标是保持内存中有足够的进程，以便 CPU 能够有效地进行多道程序设计。

2. **中级调度（也称为内存调度或换出调度）**：这个层次的调度主要涉及到内存管理，特别是在虚拟内存系统中。当内存空间不足时，中级调度器可能会选择一些进程，将它们从内存中换出到磁盘上，以释放内存空间。当内存空间充足时，它又可以将这些进程换入内存。

3. **低级调度（也称为短程调度或 CPU 调度）**：这个层次的调度决定哪个进程应该被分配到 CPU 进行执行。这个调度需要非常快速地进行，因为它会在每次 CPU 时间片结束时，或在每次发生中断时进行。

这三个层次的调度共同工作，确保了操作系统能够有效地管理进程和内存，让它们能够公平、高效地共享 CPU 和内存资源。
## 死锁
在操作系统中，死锁是指两个或更多的进程在执行过程中，因争夺资源而造成的一种僵局（即，每个进程都在等待其他进程释放资源，但这些资源只能被它们中的一个进程释放）。这导致了进程无法继续执行。

死锁通常发生在以下四个条件同时满足的情况下：

1. **互斥条件**：一个资源每次只能被一个进程使用。
2. **请求与保持条件**：一个进程因请求资源而阻塞时，对已获得的资源保持不放。
3. **不剥夺条件**：进程已获得的资源，在未使用完之前，不能强行剥夺。
4. **循环等待条件**：若干进程之间形成一种头尾相接的循环等待资源关系。

操作系统需要通过各种方法来预防、避免或解决死锁。例如，可以通过资源分配策略、死锁预防算法、死锁避免算法、死锁检测与恢复等方法来处理死锁问题。
### 常见死锁例子
以下是一些常见的死锁示例：

1. **银行家算法**：这是一个经典的死锁问题。假设有两个银行家，他们各自有一把钥匙，只有两把钥匙都在手中时，才能打开保险箱。现在，每个银行家都拿着一把钥匙，等待另一把钥匙。这就形成了死锁，因为没有人愿意放弃自己的钥匙。

2. **哲学家就餐问题**：这是另一个经典的死锁问题。假设有五位哲学家围坐在一张圆桌旁，中间放着一碗意面，每位哲学家的左右两边各有一只筷子。每位哲学家都需要两只筷子才能吃意面。现在，每位哲学家都拿起了左边的筷子，等待右边的筷子。这就形成了死锁，因为没有人能够得到两只筷子。

3. **操作系统资源分配**：在操作系统中，如果两个或多个进程同时请求相同的资源，而这些资源又不能被同时分配给多个进程，就可能发生死锁。例如，进程 A 持有资源 1 并请求资源 2，而进程 B 持有资源 2 并请求资源 1，这就形成了死锁。

以上就是一些常见的死锁示例。在实际的系统设计和编程中，我们需要通过各种策略和技术来避免死锁的发生。
### 避免死锁
避免死锁的主要方法有以下几种：

1. **破坏互斥条件**：这通常很难做到，因为某些资源（如打印机、磁盘驱动器等）在任何时候都只能被一个进程使用。

2. **破坏请求和保持条件**：一种方法是要求进程在请求资源时，必须不保持任何其他资源。但这可能导致低效率，因为进程可能需要多次请求和释放资源。

3. **破坏不剥夺条件**：如果一个进程正在等待某个资源，而这个资源被另一个正在运行的进程持有，那么操作系统可以剥夺这个资源，并将其分配给等待的进程。被剥夺资源的进程稍后再重新请求资源。

4. **破坏循环等待条件**：系统对所有资源类型进行排序，每个进程都必须以升序请求资源。这样，只有当一个进程持有了编号为 i 的资源，并请求编号为 j 的资源时，才可能存在 j>i 的情况。这样就不可能形成一个环路，因为环路需要形成一个闭环，而在这种情况下，这是不可能的。

5. **使用银行家算法**：银行家算法是一种避免死锁的著名算法，它模拟了银行家如何避免贷款时的死锁。在操作系统中，当一个进程请求资源时，系统会先检查分配资源后是否安全，如果不安全则不分配，否则就分配。

以上就是一些常见的避免死锁的方法。在实际的系统设计和编程中，我们需要根据具体的需求和环境，选择合适的策略来避免死锁。
#### 银行家算法
银行家算法是一种用于避免死锁的算法，由艾兹格·迪杰斯特拉（Edsger Dijkstra）提出。这个算法的名字来源于银行家分配贷款的方式，银行家在分配贷款时，需要确保即使贷款后，也能满足其他客户的最大需求，以避免造成贷款危机。

在操作系统中，银行家算法用于管理系统资源，避免因资源分配导致的死锁。其基本思想是，当一个进程请求资源时，系统先判断分配资源后，是否能保证系统处于安全状态。如果能保证系统安全，就分配资源；否则，就不分配资源，让进程等待。

系统安全状态的判断，是通过寻找一个安全序列来实现的。安全序列是指一个进程序列{P1, P2, ..., Pn}，对于每一个进程Pi，它请求的最大资源量不超过系统当前可用资源和所有比它在序列前面的进程持有资源之和。

银行家算法的步骤如下：

1. 当一个进程请求资源时，检查请求的资源量是否超过其最大需求，如果超过，则拒绝请求。
2. 如果请求的资源量没有超过其最大需求，那么假设将资源分配给进程。
3. 查看分配后的系统状态，是否存在一个安全序列。如果存在，那么接受这个资源请求。如果不存在，那么拒绝这个资源请求。

银行家算法可以有效地避免死锁，但它需要知道进程的最大资源需求，这在实际系统中可能很难得到。此外，这个算法也有一定的开销，因为每次资源请求都需要检查系统的安全状态。
这是一个使用 Python 描述的简单银行家算法实现。假设我们有 n 个进程和 m 种类型的资源。

```python
def isSafe(processes, available, maxm, allot):
    # 创建一个数组来存储可用资源
    work = [0] * len(available)
    for i in range(len(available)):
        work[i] = available[i]

    # 创建一个数组来存储进程的完成状态
    finish = [0] * len(processes)

    # 循环，直到所有进程都被满足
    while True:
        # 查找一个尚未完成的进程，它的需要可以被当前的工作向量满足
        found = False
        for p in range(len(processes)):
            # 如果进程已经完成，跳过
            if finish[p] == 1:
                continue

            # 检查是否所有资源都可以满足
            for r in range(len(available)):
                if maxm[p][r] - allot[p][r] > work[r]:
                    break
            else:
                # 如果所有资源都可以满足，更新工作向量和完成状态
                for r in range(len(available)):
                    work[r] += allot[p][r]
                finish[p] = 1
                found = True

        # 如果没有找到可以满足的进程，跳出循环
        if not found:
            break

    # 如果所有进程都已完成，返回 True
    return False not in finish
```

在这个函数中，`processes` 是进程的数量，`available` 是一个数组，表示每种资源的可用数量，`maxm` 是一个二维数组，表示每个进程对每种资源的最大需求，`allot` 是一个二维数组，表示每个进程已经分配到的每种资源的数量。

这个函数会返回一个布尔值，表示系统是否处于安全状态。
## 周转时间 带权周转时间 完成时间
在操作系统中，周转时间（Turnaround Time）是指从进程提交到进程完成的总时间，包括等待在就绪队列中的时间、在CPU上运行的时间以及在I/O设备上等待的时间。它是衡量系统性能的一个重要指标。

带权周转时间（Weighted Turnaround Time）是周转时间与进程实际运行时间的比值。它是一个更公平的衡量标准，因为它考虑了进程的实际运行时间。如果一个进程的实际运行时间很短，但是由于系统调度等原因，它的周转时间很长，那么这个进程的带权周转时间就会很大，这反映了系统对这个进程的调度不公平。因此，系统应该尽量使每个进程的带权周转时间尽可能小。在操作系统中，周转时间（Turnaround Time）是指从进程提交到进程完成的总时间，包括等待在就绪队列中的时间、在CPU上运行的时间以及在I/O设备上等待的时间。它是衡量系统性能的一个重要指标。

带权周转时间（Weighted Turnaround Time）是周转时间与进程实际运行时间的比值。它是一个更公平的衡量标准，因为它考虑了进程的实际运行时间。如果一个进程的实际运行时间很短，但是由于系统调度等原因，它的周转时间很长，那么这个进程的带权周转时间就会很大，这反映了系统对这个进程的调度不公平。因此，系统应该尽量使每个进程的带权周转时间尽可能小。

在操作系统中，完成时间（Finish Time）是指进程从提交（开始）到完成（结束）的时间点。这是一个绝对的时间点，而不是一个时间段。例如，如果一个进程在系统时间为10的时刻开始，在系统时间为50的时刻结束，那么这个进程的完成时间就是50。完成时间常常用于计算周转时间，即完成时间减去进程开始的时间。

## 响应比
在操作系统中，响应比是一种用于进程调度的指标。它是进程等待时间与服务时间（即进程需要在CPU上运行的时间）的比值。响应比越高，进程的优先级越低。

响应比的计算公式为：

响应比 = 等待时间 / 服务时间

响应比的目标是尽量减少进程的等待时间，特别是对于那些服务时间较短的进程。这种调度策略也被称为最高响应比优先（Highest Response Ratio Next，HRRN）调度策略。
## 硬实时调度 软实时调度
在操作系统中，实时调度算法主要分为硬实时调度和软实时调度。

**硬实时调度（Hard Real-Time Scheduling）**：硬实时系统中的任务有严格的时间限制，如果任务不能在规定的时间内完成，那么将会导致严重的后果，甚至可能是灾难性的。例如，飞行控制系统、医疗监控系统等，这些系统中的任务必须在规定的时间内完成，否则可能会对人的生命安全构成威胁。硬实时系统的调度算法需要保证所有的实时任务都能在截止时间前完成。

**软实时调度（Soft Real-Time Scheduling）**：软实时系统中的任务也有时间限制，但是如果任务不能在规定的时间内完成，虽然会影响系统的性能，但不会导致严重的后果。例如，视频播放系统、网络数据传输等，这些系统中的任务如果不能在规定的时间内完成，可能会导致视频卡顿、网络延迟等问题，但不会对系统的基本功能构成威胁。软实时系统的调度算法主要是为了优化系统的性能，提高用户的体验。

硬实时调度和软实时调度的主要区别在于对任务截止时间的处理。硬实时调度必须保证所有任务在截止时间前完成，而软实时调度则允许任务在截止时间后完成。

## 抢占式调度算法
抢占式调度算法是一种操作系统中的进程调度策略。在抢占式调度算法中，当一个新的进程到达或者一个正在运行的进程在其时间片结束之前完成时，操作系统有权利重新进行进程调度。

这意味着，即使一个进程正在运行，操作系统也可以强制中断它，将CPU分配给另一个进程。这通常是因为新的进程具有更高的优先级，或者当前运行的进程已经用完了它的时间片。

抢占式调度算法可以提供更好的交互性，因为它可以保证高优先级的进程能够尽快得到运行。此外，通过合理的时间片设置，抢占式调度算法也可以防止单个进程长时间占用CPU，从而提高系统的响应性。

常见的抢占式调度算法包括轮转调度（Round Robin）、优先级调度（Priority Scheduling）、最短剩余时间优先（Shortest Remaining Time First）等。

抢占式调度算法主要包括以下几种：

1. **轮转调度（Round Robin，RR）**：每个进程被分配一个固定大小的时间片，进程在其时间片内运行。如果时间片用完，该进程就会被移出CPU，下一个进程开始运行。如果所有进程都已经运行过一次，那么就从头开始轮转。

2. **优先级调度（Priority Scheduling）**：每个进程都有一个优先级，CPU总是运行优先级最高的进程。如果有两个或更多的进程具有相同的优先级，那么使用轮转调度。

3. **最短剩余时间优先（Shortest Remaining Time First，SRTF）**：总是运行剩余运行时间最短的进程。这是最短作业优先（Shortest Job First，SJF）调度算法的抢占式版本。

4. **多级反馈队列（Multilevel Feedback Queue）**：这是一种复杂的调度算法，它定义了多个队列，每个队列有不同的优先级和时间片大小。进程首先被放入最高优先级的队列，如果它在一个时间片内没有完成，那么它就被移动到下一个优先级的队列。这种方法可以防止短进程因长进程而饿死。

以上就是一些常见的抢占式调度算法，每种算法都有其适用的场景和优缺点。
## 最早截止时间调度算法
最早截止时间优先（Earliest Deadline First，EDF）调度是一种实时操作系统中的调度算法。在这种算法中，调度器总是选择截止时间最早的任务进行执行。

EDF调度算法的主要思想是，如果一个任务的截止时间比其他任务更早，那么它应该优先得到执行，以避免错过截止时间。这种策略在处理具有严格时间限制的实时任务时非常有效。

然而，EDF调度算法也有一些缺点。例如，如果系统过载（即，所有任务的计算需求超过了可用的计算资源），那么EDF可能会导致所有任务都错过截止时间。此外，EDF也需要频繁的上下文切换，这可能会增加系统的开销。

假设我们有三个任务，每个任务的执行时间和截止时间如下：

- 任务A：执行时间3单位，截止时间为4单位
- 任务B：执行时间2单位，截止时间为5单位
- 任务C：执行时间1单位，截止时间为7单位

在最早截止时间优先（EDF）调度算法下，我们会首先执行截止时间最早的任务，也就是任务A。任务A执行完毕后，我们选择剩下的任务中截止时间最早的任务，也就是任务B。最后，我们执行任务C。

所以，任务的执行顺序为：A -> B -> C。

这种调度策略确保了所有任务都能在其截止时间前完成。然而，如果任务的执行时间和截止时间设置不合理，或者任务的计算需求超过了可用的计算资源，EDF调度可能会导致所有任务都错过截止时间。例如，如果任务A的执行时间增加到5单位，那么任务B和任务C都会错过截止时间。

在实时系统中，任务的截止时间是指任务必须在这个时间点之前完成。截止时间是由系统的实时需求决定的，通常是在任务开始时或者任务到达时就已经确定。

例如，如果一个任务是控制飞机的降落过程，那么它的截止时间可能就是飞机预计降落的时间。如果这个任务不能在截止时间前完成，那么可能会导致严重的后果。

确定任务的截止时间通常需要对系统的实时需求有深入的理解。在一些系统中，任务的截止时间可能是固定的，例如每秒必须完成一次的控制任务。在其他系统中，任务的截止时间可能是动态变化的，例如依赖于网络条件的数据传输任务。

在使用最早截止时间优先（EDF）调度算法时，任务的截止时间是非常重要的，因为它决定了任务的执行顺序。如果任务的截止时间设置不合理，那么可能会导致任务无法在截止时间前完成，从而影响系统的实时性能。
## 什么是最短剩余时间优先（SRTF）调度算法？
最短剩余时间优先（Shortest Remaining Time First，SRTF）调度算法是一种抢占式的调度算法，它是最短作业优先（Shortest Job First，SJF）调度算法的抢占版本。

在SRTF调度算法中，操作系统总是选择剩余运行时间最短的进程进行执行。如果新到达的进程的剩余运行时间比当前正在运行的进程的剩余运行时间短，那么操作系统会中断当前进程，转而执行新到达的进程。

例如，假设有两个进程A和B，进程A正在运行，还需要5个单位时间才能完成，此时进程B到达，只需要2个单位时间就能完成。在SRTF调度算法下，操作系统会中断进程A，转而执行进程B，因为进程B的剩余运行时间更短。

SRTF调度算法可以最小化平均等待时间，但是它需要完全了解进程的运行时间，这在实际系统中通常是不可能的。此外，SRTF调度算法可能会导致“饥饿”问题，即长时间运行的进程可能会被一直推迟，因为总是有新的短时间运行的进程到达。
## 什么是最高响应比优先（HRRN）调度算法？
最高响应比优先（Highest Response Ratio Next，HRRN）调度算法是一种非抢占式的调度算法，它旨在解决最短作业优先（SJF）调度算法中的“饥饿”问题。

在HRRN调度算法中，每个进程都有一个响应比，响应比是进程的等待时间和服务时间的比值。操作系统总是选择响应比最高的进程进行执行。

响应比的计算公式为：(等待时间 + 服务时间) / 服务时间

这种策略的优点是，它既考虑了进程的等待时间，也考虑了进程的服务时间。因此，既能保证短进程快速得到执行，又能防止长进程饿死。

例如，假设有两个进程A和B，进程A的服务时间为10单位，已经等待了20单位，进程B的服务时间为5单位，已经等待了10单位。那么，进程A的响应比为(20+10)/10=3，进程B的响应比为(10+5)/5=3。因此，这两个进程的响应比相同，可以选择任意一个进行执行。

然而，HRRN调度算法的缺点是，它需要知道进程的服务时间，这在实际系统中通常是不可能的。此外，计算响应比也需要一定的开销。