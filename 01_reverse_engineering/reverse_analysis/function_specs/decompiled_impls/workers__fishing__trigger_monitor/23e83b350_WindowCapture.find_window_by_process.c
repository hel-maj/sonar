/* ===== 23e83b350 workers.fishing.trigger_monitor:203 ===== */
/* ghidra_name=FUN_23e83b350 entry=23e83b350 size=4116 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e83b350(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong *plVar2;
  code *pcVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined1 auVar7 [16];
  char cVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  code *pcVar16;
  undefined4 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  longlong *plStack_c0;
  longlong *plStack_b0;
  undefined1 auStack_98 [16];
  longlong *plStack_88;
  code *pcStack_78;
  code *pcStack_70;
  longlong *plStack_68;
  
  plVar5 = _DAT_23eede4a0;
  plVar9 = _DAT_23eedc238;
  pcVar1 = (code *)param_3[2];
  plVar2 = (longlong *)*param_3;
  pcVar3 = (code *)param_3[1];
  plStack_88 = (longlong *)0x0;
  auStack_98 = (undefined1  [16])0x0;
  if ((pcVar1 == _Py_NoneStruct_exref) || (pcVar3 == _Py_NoneStruct_exref)) {
    *_DAT_23eedc238 = *_DAT_23eedc238 + 1;
LAB_23e83b953:
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
LAB_23e83b900:
    *(longlong *)pcVar3 = *(longlong *)pcVar3 + -1;
    if (*(longlong *)pcVar3 == 0) {
      (**(code **)(*(longlong *)(pcVar3 + 8) + 0x30))(pcVar3);
    }
    *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
    if (*(longlong *)pcVar1 != 0) {
      return plVar9;
    }
    (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
    return plVar9;
  }
  if (_DAT_23eede4a0 == (longlong *)0x0) {
LAB_23e83b3ce:
    _DAT_23eede4a0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede498,DAT_23eede5a0,0x48);
  }
  else {
    lVar11 = *_DAT_23eede4a0;
    if (1 < lVar11) {
      *_DAT_23eede4a0 = lVar11 + -1;
      goto LAB_23e83b3ce;
    }
    if (_DAT_23eede4a0[2] != 0) {
      *_DAT_23eede4a0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
      goto LAB_23e83b3ce;
    }
  }
  plVar5 = _DAT_23eede4a0;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eede4a0 + 9;
  lVar4 = *(longlong *)(lVar11 + 8);
  _DAT_23eede4a0[0xf] = lVar4;
  *(longlong **)(lVar11 + 8) = plVar9;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar5 = *plVar5 + 1;
  uVar18 = DAT_23eedbff8;
  *(undefined4 *)(plVar5 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(pcVar3,uVar18);
  if (plVar9 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar17 = 0xd1;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar16 = (code *)0x0;
    goto LAB_23e83babd;
  }
  plVar10 = (longlong *)FUN_23e8bd600(param_1,plVar9);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if (plVar10 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    pcVar16 = (code *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar17 = 0xd1;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e83babd;
  }
  lVar11 = *plVar10 + -1;
  if (plVar10[2] == 1) {
    *plVar10 = lVar11;
    if ((int)plVar10[3] != 3) goto LAB_23e83b496;
    if (lVar11 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    lVar11 = FUN_23e8db510();
    if (lVar11 == 0) {
      plVar10 = (longlong *)0x0;
      FUN_23e915740(param_1,auStack_98,DAT_23eedc000);
      uVar17 = 0xd2;
      pcVar16 = (code *)0x0;
      goto LAB_23e83babd;
    }
    plVar9 = (longlong *)FUN_23e8bc2f0(lVar11,DAT_23eedc008);
    if (plVar9 == (longlong *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      plVar10 = (longlong *)0x0;
      pcVar16 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar17 = 0xd2;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e83babd;
    }
    lVar11 = FUN_23e8db510();
    if (lVar11 == 0) {
      FUN_23e915740(param_1,auStack_98,DAT_23eedc000);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      plVar10 = (longlong *)0x0;
      uVar17 = 0xd2;
      pcVar16 = (code *)0x0;
      goto LAB_23e83babd;
    }
    pcVar15 = (code *)FUN_23e8bc2f0(lVar11,_DAT_23eedc240);
    if (pcVar15 == (code *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar9 = *plVar9 + -1;
      plVar10 = (longlong *)0x0;
      if (*plVar9 == 0) {
        pcVar16 = (code *)0x0;
        (**(code **)(plVar9[1] + 0x30))(plVar9);
        uVar17 = 0xd2;
      }
      else {
        pcVar16 = (code *)0x0;
        uVar17 = 0xd2;
      }
      goto LAB_23e83babd;
    }
    *(undefined4 *)(plVar5 + 5) = 0xd2;
    pcStack_78 = pcVar3;
    pcStack_70 = pcVar15;
    pcVar16 = (code *)FUN_23e94ed00(param_1,plVar9,&pcStack_78);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
    if (*(longlong *)pcVar15 == 0) {
      (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
    }
    if (pcVar16 == (code *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar17 = 0xd2;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e83babd;
    }
  }
  else {
    *plVar10 = lVar11;
LAB_23e83b496:
    if (lVar11 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    *(longlong *)pcVar3 = *(longlong *)pcVar3 + 1;
    pcVar16 = pcVar3;
  }
  lVar11 = FUN_23e8db510();
  if (lVar11 == 0) {
    FUN_23e915740(param_1,auStack_98,DAT_23eedc000);
    uVar17 = 0xd7;
    plVar10 = (longlong *)0x0;
    goto LAB_23e83babd;
  }
  plVar9 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eedc248);
  if (plVar9 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar17 = 0xd7;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e83babd;
  }
  lVar11 = FUN_23e8db510();
  if (lVar11 == 0) {
    FUN_23e915740(param_1,auStack_98,DAT_23eedc000);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    uVar17 = 0xd7;
    plVar10 = (longlong *)0x0;
    goto LAB_23e83babd;
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23eedc250);
  if (plVar12 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      plVar10 = (longlong *)0x0;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
      uVar17 = 0xd7;
    }
    else {
      plVar10 = (longlong *)0x0;
      uVar17 = 0xd7;
    }
    goto LAB_23e83babd;
  }
  *(undefined4 *)(plVar5 + 5) = 0xd7;
  pcStack_78 = pcVar16;
  pcStack_70 = pcVar1;
  plStack_68 = plVar12;
  plVar10 = (longlong *)FUN_23e956150(param_1,plVar9,&pcStack_78);
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if (plVar10 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    uVar17 = 0xd7;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e83babd;
  }
  lVar11 = FUN_23e8db510();
  if (lVar11 == 0) {
    FUN_23e915740(param_1,auStack_98,DAT_23eedc000);
    plVar9 = plStack_88;
    uVar18 = auStack_98._0_8_;
    uVar19 = auStack_98._8_8_;
  }
  else {
    *(undefined4 *)(plVar5 + 5) = 0xd8;
    plVar9 = (longlong *)FUN_23e915840(param_1,lVar11,_DAT_23eedc258,plVar10);
    if (plVar9 != (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a388310(plVar9);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      if (plVar12 != (longlong *)0x0) {
        plVar13 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
        if ((plVar13 == (longlong *)0x0) &&
           (plVar13 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,4), plVar13 == (longlong *)0x0)
           ) {
          plStack_c0 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
        }
        else {
          plVar14 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
          if ((plVar14 == (longlong *)0x0) &&
             (plVar14 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,1,4),
             plVar14 == (longlong *)0x0)) {
            plStack_c0 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
          }
          else {
            plStack_b0 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
            if ((plStack_b0 == (longlong *)0x0) &&
               (plStack_b0 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,2,4),
               plStack_b0 == (longlong *)0x0)) {
              plStack_c0 = (longlong *)0x0;
            }
            else {
              plStack_c0 = (longlong *)(**(code **)(plVar12[1] + 0xe0))(plVar12);
              if (((plStack_c0 != (longlong *)0x0) ||
                  (plStack_c0 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,3,4),
                  plStack_c0 != (longlong *)0x0)) &&
                 (cVar8 = FUN_23a3884a0(param_1,auStack_98,plVar12,4), cVar8 != '\0')) {
                lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar9 = *(longlong **)(lVar11 + 0x28);
                plVar5 = (longlong *)plVar9[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
                *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                if (plVar5 != (longlong *)0x0) {
                  plVar9[2] = 0;
                  *plVar5 = *plVar5 + -1;
                  if (*plVar5 == 0) {
                    (**(code **)(plVar5[1] + 0x30))();
                  }
                }
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                plVar9[0xf] = 0;
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                if (*plStack_b0 == 0) {
                  (**(code **)(plStack_b0[1] + 0x30))();
                }
                if (*plStack_c0 == 0) {
                  (**(code **)(plStack_c0[1] + 0x30))();
                }
                lVar11 = *(longlong *)(param_1 + 0x10);
                plVar9 = *(longlong **)(lVar11 + 0xe20);
                if (plVar9 == (longlong *)0x0) {
                  plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar4 = plVar9[3];
                  *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
                  *(longlong *)(lVar11 + 0xe20) = lVar4;
                  *plVar9 = 1;
                }
                lVar11 = *(longlong *)
                          (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
                lVar4 = plVar9[-1];
                puVar6 = *(undefined8 **)(lVar11 + 8);
                *puVar6 = plVar9 + -2;
                plVar9[-2] = lVar11;
                plVar9[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
                *(longlong **)(lVar11 + 8) = plVar9 + -2;
                *plVar14 = *plVar14 + 1;
                plVar9[3] = (longlong)plVar14;
                *plStack_c0 = *plStack_c0 + 1;
                plVar9[4] = (longlong)plStack_c0;
                *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
                if (*(longlong *)pcVar16 == 0) {
                  (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
                  *plVar10 = *plVar10 + -1;
                  lVar11 = *plVar10;
                }
                else {
                  *plVar10 = *plVar10 + -1;
                  lVar11 = *plVar10;
                }
                if (lVar11 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                lVar11 = *plStack_b0;
                *plStack_b0 = lVar11 + -1;
                if (lVar11 + -1 == 0) {
                  (**(code **)(plStack_b0[1] + 0x30))();
                }
                lVar11 = *plStack_c0;
                *plStack_c0 = lVar11 + -1;
                if (lVar11 + -1 == 0) {
                  (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
                  *plVar2 = *plVar2 + -1;
                  if (*plVar2 == 0) {
                    (**(code **)(plVar2[1] + 0x30))(plVar2);
                  }
                  goto LAB_23e83b900;
                }
                goto LAB_23e83b953;
              }
            }
          }
        }
        plVar9 = plStack_88;
        uVar18 = auStack_98._0_8_;
        uVar19 = auStack_98._8_8_;
        plStack_88 = (longlong *)0x0;
        auStack_98 = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        plStack_88 = (longlong *)0x0;
        auStack_98 = (undefined1  [16])0x0;
        if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if ((plStack_b0 != (longlong *)0x0) &&
           (lVar11 = *plStack_b0, *plStack_b0 = lVar11 + -1, lVar11 + -1 == 0)) {
          (**(code **)(plStack_b0[1] + 0x30))();
        }
        if ((plStack_c0 != (longlong *)0x0) &&
           (lVar11 = *plStack_c0, *plStack_c0 = lVar11 + -1, lVar11 + -1 == 0)) {
          (**(code **)(plStack_c0[1] + 0x30))();
        }
        goto LAB_23e83baa7;
      }
    }
    uVar18 = *(undefined8 *)(param_1 + 0x60);
    plVar9 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar19 = *(undefined8 *)(param_1 + 0x68);
  }
LAB_23e83baa7:
  uVar17 = 0xd8;
  auStack_98._8_8_ = uVar19;
  auStack_98._0_8_ = uVar18;
  plStack_88 = plVar9;
LAB_23e83babd:
  plVar12 = plStack_88;
  plVar9 = DAT_23ed6a4f8;
  if (plStack_88 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar12 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar12;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar15 = _PyRuntime_exref;
    plVar9[2] = 0;
    plVar9[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar11 = *(longlong *)(pcVar15 + 0x1f8);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar17;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar4 = plVar9[-1];
    puVar6 = *(undefined8 **)(lVar11 + 8);
    *puVar6 = plVar9 + -2;
    plVar9[-2] = lVar11;
    plVar9[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar11 + 8) = plVar9 + -2;
    plVar12 = plVar9;
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      (**(code **)(plStack_88[1] + 0x30))(plStack_88);
    }
  }
  else if ((longlong *)plStack_88[3] != plVar5) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar9 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar13 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar13;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar15 = _PyRuntime_exref;
    plVar9[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar11 = *(longlong *)(pcVar15 + 0x1f8);
    *(undefined4 *)((longlong)plVar9 + 0x24) = uVar17;
    *(undefined4 *)(plVar9 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar4 = plVar9[-1];
    puVar6 = *(undefined8 **)(lVar11 + 8);
    *puVar6 = plVar9 + -2;
    plVar9[-2] = lVar11;
    plVar9[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar11 + 8) = plVar9 + -2;
    plVar9[2] = (longlong)plVar12;
    *plVar12 = *plVar12 + 1;
    plVar12 = plVar9;
    if ((plStack_88 != (longlong *)0x0) && (*plStack_88 = *plStack_88 + -1, *plStack_88 == 0)) {
      (**(code **)(plStack_88[1] + 0x30))();
    }
  }
  plStack_88 = plVar12;
  FUN_23e8bba40(plVar5,"ooooooooo",plVar2,pcVar3,pcVar1,pcVar16,plVar10,0,0,0,0);
  if (_DAT_23eede4a0 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eede4a0 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar11 + 0x28);
  plVar5 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar5 = plStack_88;
  auVar7 = auStack_98;
  plVar9[0xf] = 0;
  auStack_98 = (undefined1  [16])0x0;
  plStack_88 = (longlong *)0x0;
  if ((pcVar16 != (code *)0x0) &&
     (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 == 0)) {
    (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar2 = *plVar2 + -1;
  auStack_98 = auVar7;
  plStack_88 = plVar5;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *(longlong *)pcVar3 = *(longlong *)pcVar3 + -1;
  if (*(longlong *)pcVar3 == 0) {
    (**(code **)(*(longlong *)(pcVar3 + 8) + 0x30))(pcVar3);
  }
  *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
  if (*(longlong *)pcVar1 == 0) {
    (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
  }
  FUN_23a33aa70(param_1,auStack_98._0_8_,auStack_98._8_8_,plStack_88);
  return (longlong *)0x0;
}
