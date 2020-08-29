# ft_printf
Recode printf. Learn how to use variadic arguments.

[Subject](https://cdn.intra.42.fr/pdf/pdf/10819/en.subject.pdf)

### 🎯 Object
#### ✅ Mandatory part
- The prototype of ft_printf should be `int ft_printf(const char *, ...);`
- It is recode version of the libc’s printf function
- It must not do the buffer management like the real printf
- It will manage the following conversions: `cspdiuxX%`
- It will manage any combination of the following flags: `-0.*` and minimum field width with all conversions
- It will be compared with the real printf

#### 🎉 Bonus part
- Manage one or more of the following conversions
  - [x] `n`
  - [ ] `f`
  - [ ] `g`
  - [ ] `e`
- [ ] Manage one or more of the following flags: l ll h hh
- [ ] Manage all the following flags: ’# +’ (yes, one of them is a space)

### 🧾 Result
#### 💯 Score
101/100

#### 👨‍🏫 Evaluated by Moulinette
> test_spdxiucpercent: 8/8 correct functions | test_fields: 4/4 correct functions | bonus_test: 1/11 correct functions
