/* ===== 23e7ce9d0 workers.fishing.meal_system:73 ===== */
/* ghidra_name=FUN_23e7ce9d0 entry=23e7ce9d0 size=3208 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e7ce9d0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  longlong lVar4;
  undefined8 *puVar5;
  code *pcVar6;
  longlong *plVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined4 uStack_88;
  undefined1 auStack_78 [16];
  longlong *plStack_68;
  
  plVar11 = _DAT_23eeded50;
  plVar1 = (longlong *)*param_3;
  plStack_68 = (longlong *)0x0;
  auStack_78._0_8_ = 0;
  auStack_78._8_8_ = 0;
  if (_DAT_23eeded50 == (longlong *)0x0) {
LAB_23e7cea24:
    _DAT_23eeded50 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeded48,DAT_23eed7940,0x28);
  }
  else {
    lVar12 = *_DAT_23eeded50;
    if (1 < lVar12) {
      *_DAT_23eeded50 = lVar12 + -1;
      goto LAB_23e7cea24;
    }
    if (_DAT_23eeded50[2] != 0) {
      *_DAT_23eeded50 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      goto LAB_23e7cea24;
    }
  }
  plVar3 = _DAT_23eeded50;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar11 = _DAT_23eeded50 + 9;
  lVar2 = *(longlong *)(lVar12 + 8);
  _DAT_23eeded50[0xf] = lVar2;
  *(longlong **)(lVar12 + 8) = plVar11;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eed70a8);
  if (plVar11 == (longlong *)0x0) {
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar16 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    uStack_88 = 0x4b;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e7cf042;
  }
  iVar9 = FUN_23a35f020(plVar11);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (iVar9 == -1) {
LAB_23e7cf2b0:
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar16 = (longlong *)0x0;
    plVar14 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_88 = 0x4b;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e7cf042;
  }
  if (iVar9 == 0) {
LAB_23e7ceaee:
    plVar17 = plRam000000023eed7120;
    plVar14 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    *plRam000000023eed7120 = *plRam000000023eed7120 + 1;
LAB_23e7ceb03:
    lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar3 = *(longlong **)(lVar12 + 0x28);
    plVar15 = (longlong *)plVar3[2];
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
    *(undefined4 *)(plVar3 + 8) = 0xffffffff;
    if (plVar15 != (longlong *)0x0) {
      plVar3[2] = 0;
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))();
      }
    }
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    plVar3[0xf] = 0;
    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
      (**(code **)(plVar13[1] + 0x30))(plVar13);
    }
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    *plVar1 = *plVar1 + -1;
    if (*plVar1 != 0) {
      return plVar17;
    }
    (**(code **)(plVar1[1] + 0x30))(plVar1);
    return plVar17;
  }
  lVar12 = FUN_23e8de4a0();
  if (lVar12 == 0) {
    FUN_23e915740(param_1,auStack_78,uRam000000023eed70c0);
  }
  else {
    plVar13 = (longlong *)FUN_23e8bc2f0(lVar12,uRam000000023eed7118);
    if (plVar13 == (longlong *)0x0) {
      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      plVar16 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar11 = (longlong *)0x0;
      uStack_88 = 0x4b;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar13 = (longlong *)0x0;
      goto LAB_23e7cf042;
    }
    plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eed70a8);
    if (plVar11 != (longlong *)0x0) {
      *(undefined4 *)(plVar3 + 5) = 0x4b;
      plVar14 = (longlong *)FUN_23e914090(param_1,plVar13,plVar11);
      *plVar13 = *plVar13 + -1;
      if (*plVar13 == 0) {
        (**(code **)(plVar13[1] + 0x30))(plVar13);
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar14 == (longlong *)0x0) {
        auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        plVar16 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar11 = (longlong *)0x0;
        uStack_88 = 0x4b;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar14 = (longlong *)0x0;
        goto LAB_23e7cf042;
      }
      uVar10 = FUN_23a35f020(plVar14);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (uVar10 == 0xffffffff) goto LAB_23e7cf2b0;
      if ((uVar10 & 1) == 0) goto LAB_23e7ceaee;
      lVar12 = FUN_23e8de4a0();
      if (lVar12 == 0) {
        FUN_23e915740(param_1,auStack_78,uRam000000023eed70c0);
        plVar17 = plStack_68;
        uVar18 = auStack_78._0_8_;
        uVar19 = auStack_78._8_8_;
      }
      else {
        plVar11 = (longlong *)FUN_23e8bc2f0(lVar12,uRam000000023eed7128);
        if (plVar11 != (longlong *)0x0) {
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eed70a8);
          if (plVar13 == (longlong *)0x0) {
            auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
            auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar11 = *plVar11 + -1;
            plVar17 = plStack_68;
            uVar18 = auStack_78._0_8_;
            uVar19 = auStack_78._8_8_;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
              plVar17 = plStack_68;
              uVar18 = auStack_78._0_8_;
              uVar19 = auStack_78._8_8_;
            }
            goto LAB_23e7cf028;
          }
          *(undefined4 *)(plVar3 + 5) = 0x4e;
          plVar14 = (longlong *)FUN_23e914090(param_1,plVar11,plVar13);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (plVar14 != (longlong *)0x0) {
            plVar15 = (longlong *)FUN_23a388310(plVar14);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (plVar15 != (longlong *)0x0) {
              plVar11 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
              if ((plVar11 == (longlong *)0x0) &&
                 (plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,0,4),
                 plVar11 == (longlong *)0x0)) {
                plVar16 = (longlong *)0x0;
                plVar14 = (longlong *)0x0;
                plVar13 = (longlong *)0x0;
              }
              else {
                plVar13 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                if ((plVar13 == (longlong *)0x0) &&
                   (plVar13 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,1,4),
                   plVar13 == (longlong *)0x0)) {
                  plVar16 = (longlong *)0x0;
                  plVar14 = (longlong *)0x0;
                }
                else {
                  plVar14 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                  if ((plVar14 == (longlong *)0x0) &&
                     (plVar14 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,2,4),
                     plVar14 == (longlong *)0x0)) {
                    plVar16 = (longlong *)0x0;
                  }
                  else {
                    plVar16 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                    if (((plVar16 != (longlong *)0x0) ||
                        (plVar16 = (longlong *)FUN_23a3c1b70(param_1,auStack_78,3,4),
                        plVar16 != (longlong *)0x0)) &&
                       (cVar8 = FUN_23a3884a0(param_1,auStack_78,plVar15,4), cVar8 != '\0')) {
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        (**(code **)(plVar15[1] + 0x30))(plVar15);
                      }
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      if (*plVar16 == 0) {
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                      }
                      lVar12 = FUN_23e8c6640(plVar14,plVar11);
                      if (lVar12 != 0) {
                        lVar2 = *(longlong *)(param_1 + 0x10);
                        plVar17 = *(longlong **)(lVar2 + 0xe20);
                        if (plVar17 == (longlong *)0x0) {
                          plVar17 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                        }
                        else {
                          lVar4 = plVar17[3];
                          *(int *)(lVar2 + 0xebc) = *(int *)(lVar2 + 0xebc) + -1;
                          *(longlong *)(lVar2 + 0xe20) = lVar4;
                          *plVar17 = 1;
                        }
                        pcVar6 = _PyRuntime_exref;
                        plVar17[4] = 0;
                        lVar2 = *(longlong *)
                                 (*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
                        lVar4 = plVar17[-1];
                        puVar5 = *(undefined8 **)(lVar2 + 8);
                        *puVar5 = plVar17 + -2;
                        plVar17[-2] = lVar2;
                        plVar17[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
                        *(longlong **)(lVar2 + 8) = plVar17 + -2;
                        plVar17[3] = lVar12;
                        lVar12 = FUN_23e8c6640(plVar16,plVar13);
                        if (lVar12 == 0) {
                          auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                          auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          uStack_88 = 0x4f;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *plVar17 = *plVar17 + -1;
                          if (*plVar17 == 0) {
                            (**(code **)(plVar17[1] + 0x30))(plVar17);
                            uStack_88 = 0x4f;
                          }
                          goto LAB_23e7cf042;
                        }
                        plVar17[4] = lVar12;
                        goto LAB_23e7ceb03;
                      }
                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      plStack_68 = *(longlong **)(param_1 + 0x70);
                      uStack_88 = 0x4f;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      goto LAB_23e7cf042;
                    }
                  }
                }
              }
              plVar17 = plStack_68;
              uVar19 = auStack_78._8_8_;
              uVar18 = auStack_78._0_8_;
              plStack_68 = (longlong *)0x0;
              auStack_78 = (undefined1  [16])0x0;
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              plStack_68 = (longlong *)0x0;
              auStack_78._0_8_ = 0;
              auStack_78._8_8_ = 0;
              if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              goto LAB_23e7cf028;
            }
          }
        }
        uVar18 = *(undefined8 *)(param_1 + 0x60);
        plVar17 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar19 = *(undefined8 *)(param_1 + 0x68);
      }
LAB_23e7cf028:
      uStack_88 = 0x4e;
      plVar16 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plStack_68 = plVar17;
      auStack_78._0_8_ = uVar18;
      auStack_78._8_8_ = uVar19;
      goto LAB_23e7cf042;
    }
    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar13 = *plVar13 + -1;
    plVar11 = (longlong *)0x0;
    if (*plVar13 != 0) {
      plVar16 = (longlong *)0x0;
      plVar14 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      uStack_88 = 0x4b;
      goto LAB_23e7cf042;
    }
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  plVar11 = (longlong *)0x0;
  plVar16 = (longlong *)0x0;
  plVar14 = (longlong *)0x0;
  plVar13 = (longlong *)0x0;
  uStack_88 = 0x4b;
LAB_23e7cf042:
  plVar15 = plStack_68;
  plVar17 = DAT_23ed6a4f8;
  if (plStack_68 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar17 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar15 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar15;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar17[2] = 0;
    plVar17[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar12 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar17 + 0x24) = uStack_88;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)(plVar17 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar2 = plVar17[-1];
    puVar5 = *(undefined8 **)(lVar12 + 8);
    *puVar5 = plVar17 + -2;
    plVar17[-2] = lVar12;
    plVar17[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar12 + 8) = plVar17 + -2;
    plVar15 = plVar17;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      (**(code **)(plStack_68[1] + 0x30))(plStack_68);
    }
  }
  else if ((longlong *)plStack_68[3] != plVar3) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar17 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar7 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar7;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar17[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar12 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar17 + 0x24) = uStack_88;
    *(undefined4 *)(plVar17 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar2 = plVar17[-1];
    puVar5 = *(undefined8 **)(lVar12 + 8);
    *puVar5 = plVar17 + -2;
    plVar17[-2] = lVar12;
    plVar17[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar12 + 8) = plVar17 + -2;
    plVar17[2] = (longlong)plVar15;
    *plVar15 = *plVar15 + 1;
    plVar15 = plVar17;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      (**(code **)(plStack_68[1] + 0x30))();
    }
  }
  plStack_68 = plVar15;
  FUN_23e8bba40(plVar3,"ooooo",plVar1,plVar11,plVar13,plVar14,plVar16);
  if (_DAT_23eeded50 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeded50 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar12 + 0x28);
  plVar17 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar17 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar17 = plStack_68;
  uVar19 = auStack_78._8_8_;
  uVar18 = auStack_78._0_8_;
  plVar3[0xf] = 0;
  auStack_78 = (undefined1  [16])0x0;
  plStack_68 = (longlong *)0x0;
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  *plVar1 = *plVar1 + -1;
  plStack_68 = plVar17;
  auStack_78._0_8_ = uVar18;
  auStack_78._8_8_ = uVar19;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_78._0_8_,auStack_78._8_8_,plStack_68);
  return (longlong *)0x0;
}
