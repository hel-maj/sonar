/* ===== 23e2e0830 ui.hotkey_dialog:171 ===== */
/* ghidra_name=FUN_23e2e0830 entry=23e2e0830 size=9430 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e2e0830(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong lVar4;
  undefined8 *puVar5;
  code *pcVar6;
  longlong *plVar7;
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  undefined4 uVar19;
  longlong *plVar20;
  undefined8 extraout_XMM0_Qa;
  undefined8 uVar21;
  undefined8 extraout_XMM0_Qa_00;
  undefined8 extraout_XMM0_Qa_01;
  undefined8 uVar22;
  undefined1 local_78 [16];
  longlong *local_68 [5];
  
  plVar1 = (longlong *)*param_3;
  lVar13 = *(longlong *)(param_1 + 0x10);
  plVar2 = (longlong *)param_3[1];
  local_68[0] = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  if (*(int *)(lVar13 + 0x1188) == 0) {
    plVar17 = (longlong *)FUN_23a33a530(PyList_Type_exref);
    lVar13 = *(longlong *)(param_1 + 0x10);
    iVar9 = *(int *)(lVar13 + 0x1188);
  }
  else {
    iVar9 = *(int *)(lVar13 + 0x1188) + -1;
    *(int *)(lVar13 + 0x1188) = iVar9;
    plVar17 = *(longlong **)(lVar13 + 0xf08 + (longlong)iVar9 * 8);
    *plVar17 = 1;
  }
  pcVar6 = _PyRuntime_exref;
  plVar17[2] = 0;
  plVar17[4] = 0;
  lVar3 = *(longlong *)(pcVar6 + 0x1f8);
  plVar17[3] = 0;
  lVar3 = *(longlong *)(*(longlong *)(lVar3 + 0x10) + 0x2e8);
  lVar4 = plVar17[-1];
  puVar5 = *(undefined8 **)(lVar3 + 8);
  *puVar5 = plVar17 + -2;
  plVar17[-2] = lVar3;
  plVar17[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
  *(longlong **)(lVar3 + 8) = plVar17 + -2;
  if (iVar9 == 0) {
    plVar18 = (longlong *)FUN_23a33a530(PyList_Type_exref);
  }
  else {
    *(int *)(lVar13 + 0x1188) = iVar9 + -1;
    plVar18 = *(longlong **)(lVar13 + 0xf08 + (longlong)(iVar9 + -1) * 8);
    *plVar18 = 1;
  }
  pcVar6 = _PyRuntime_exref;
  plVar18[2] = 0;
  plVar18[4] = 0;
  plVar10 = _DAT_23eeb01d8;
  lVar13 = *(longlong *)(pcVar6 + 0x1f8);
  plVar18[3] = 0;
  lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
  lVar3 = plVar18[-1];
  puVar5 = *(undefined8 **)(lVar13 + 8);
  *puVar5 = plVar18 + -2;
  plVar18[-2] = lVar13;
  plVar18[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
  *(longlong **)(lVar13 + 8) = plVar18 + -2;
  if (plVar10 == (longlong *)0x0) {
LAB_23e2e09b3:
    plVar10 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb01d0,DAT_23eeb0268);
    _DAT_23eeb01d8 = plVar10;
  }
  else {
    lVar13 = *plVar10;
    if (1 < lVar13) {
      *plVar10 = lVar13 + -1;
      goto LAB_23e2e09b3;
    }
    if (plVar10[2] != 0) {
      *plVar10 = lVar13 + -1;
      if (lVar13 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e2e09b3;
    }
  }
  lVar13 = *(longlong *)(param_1 + 0x38);
  lVar3 = *(longlong *)(lVar13 + 8);
  plVar10[0xf] = lVar3;
  *(longlong **)(lVar13 + 8) = plVar10 + 9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar10[0xe] != 0)))) {
    plVar11 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar10[0xe] + 0x10) = plVar11;
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + 1;
    }
  }
  *plVar10 = *plVar10 + 1;
  *(undefined4 *)(plVar10 + 8) = 0;
  plVar11 = (longlong *)FUN_23ebf7180(plVar2);
  if (plVar11 == (longlong *)0x0) {
    local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    local_68[0] = *(longlong **)(param_1 + 0x70);
    plVar20 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar19 = 0xb0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e2e1286;
  }
  if (plVar1 == (longlong *)0x0) {
    lVar13 = plVar11[1];
    pcVar6 = *(code **)(lVar13 + 0xe0);
    plVar14 = (longlong *)0x0;
    while (pcVar6 != (code *)0x0) {
      plVar12 = (longlong *)(*pcVar6)(plVar11);
      if (plVar12 == (longlong *)0x0) {
        plVar20 = (longlong *)0x0;
        goto LAB_23e2e0d33;
      }
      if (plVar14 == (longlong *)0x0) {
        *plVar12 = *plVar12 + 1;
      }
      else {
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
          lVar13 = *plVar12;
        }
        else {
          lVar13 = *plVar12;
        }
        *plVar12 = lVar13 + 1;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
      }
      lVar13 = FUN_23e8f5ff0();
      plVar20 = (longlong *)0x0;
      if (lVar13 == 0) goto LAB_23e2e11fa;
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
      plVar20 = (longlong *)0x0;
      if (plVar14 == (longlong *)0x0) goto LAB_23e2e1b35;
      lVar13 = FUN_23e8bc2f0(plVar14,_DAT_23eead670);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (lVar13 == 0) {
LAB_23e2e29a8:
        plVar20 = (longlong *)0x0;
        goto LAB_23e2e1b35;
      }
      lVar3 = *(longlong *)(param_1 + 0x10);
      plVar14 = *(longlong **)(lVar3 + 0xe28);
      if (plVar14 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
      }
      else {
        lVar4 = plVar14[3];
        *(int *)(lVar3 + 0xec0) = *(int *)(lVar3 + 0xec0) + -1;
        *(longlong *)(lVar3 + 0xe28) = lVar4;
        *plVar14 = 1;
      }
      pcVar6 = _PyRuntime_exref;
      *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
      lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
      lVar4 = plVar14[-1];
      puVar5 = *(undefined8 **)(lVar3 + 8);
      *puVar5 = plVar14 + -2;
      plVar14[-2] = lVar3;
      plVar14[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
      *(longlong **)(lVar3 + 8) = plVar14 + -2;
      plVar14[3] = lVar13;
      lVar13 = FUN_23e8f5ff0();
      plVar20 = (longlong *)0x0;
      if (lVar13 == 0) goto LAB_23e2e1565;
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
      plVar20 = (longlong *)0x0;
      if (plVar15 == (longlong *)0x0) goto LAB_23e2e1a95;
      lVar13 = FUN_23e8bc2f0(plVar15,_DAT_23eead678);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if (lVar13 == 0) {
LAB_23e2e29b0:
        plVar20 = (longlong *)0x0;
        goto LAB_23e2e1a95;
      }
      plVar14[4] = lVar13;
      lVar13 = FUN_23e8f5ff0();
      plVar20 = (longlong *)0x0;
      if (lVar13 == 0) goto LAB_23e2e1565;
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
      plVar20 = (longlong *)0x0;
      if (plVar15 == (longlong *)0x0) goto LAB_23e2e1a95;
      lVar13 = FUN_23e8bc2f0(plVar15,_DAT_23eead680);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if (lVar13 == 0) goto LAB_23e2e29b0;
      plVar14[5] = lVar13;
      iVar9 = PySequence_Contains(plVar14,plVar12);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (iVar9 == -1) goto LAB_23e2e29a8;
      if (iVar9 != 1) {
        lVar13 = FUN_23e8f5ff0();
        plVar20 = (longlong *)0x0;
        if (lVar13 == 0) goto LAB_23e2e1e35;
        plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
        plVar20 = (longlong *)0x0;
        if (plVar14 == (longlong *)0x0) goto LAB_23e2e1f25;
        lVar13 = FUN_23e8bc2f0(plVar14,_DAT_23eead698);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if (lVar13 == 0) {
LAB_23e2e2cda:
          plVar20 = (longlong *)0x0;
          goto LAB_23e2e1f25;
        }
        lVar3 = *(longlong *)(param_1 + 0x10);
        plVar14 = *(longlong **)(lVar3 + 0xe30);
        if (plVar14 == (longlong *)0x0) {
          plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
        }
        else {
          lVar4 = plVar14[3];
          *(int *)(lVar3 + 0xec4) = *(int *)(lVar3 + 0xec4) + -1;
          *(longlong *)(lVar3 + 0xe30) = lVar4;
          *plVar14 = 1;
        }
        pcVar6 = _PyRuntime_exref;
        plVar14[6] = 0;
        *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
        lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
        lVar4 = plVar14[-1];
        puVar5 = *(undefined8 **)(lVar3 + 8);
        *puVar5 = plVar14 + -2;
        plVar14[-2] = lVar3;
        plVar14[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
        *(longlong **)(lVar3 + 8) = plVar14 + -2;
        plVar14[3] = lVar13;
        lVar13 = FUN_23e8f5ff0();
        plVar20 = (longlong *)0x0;
        if (lVar13 == 0) goto LAB_23e2e1a35;
        plVar15 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
        plVar20 = (longlong *)0x0;
        if (plVar15 == (longlong *)0x0) goto LAB_23e2e1e75;
        lVar13 = FUN_23e8bc2f0(plVar15,_DAT_23eead6a0);
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if (lVar13 != 0) {
          plVar14[4] = lVar13;
          lVar13 = FUN_23e8f5ff0();
          plVar20 = (longlong *)0x0;
          if (lVar13 == 0) goto LAB_23e2e1a35;
          plVar15 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
          plVar20 = (longlong *)0x0;
          if (plVar15 == (longlong *)0x0) goto LAB_23e2e1e75;
          lVar13 = FUN_23e8bc2f0(plVar15,_DAT_23eead6a8);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if (lVar13 != 0) {
            plVar14[5] = lVar13;
            lVar13 = FUN_23e8f5ff0();
            plVar20 = (longlong *)0x0;
            if (lVar13 == 0) goto LAB_23e2e1a35;
            plVar15 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
            plVar20 = (longlong *)0x0;
            if (plVar15 == (longlong *)0x0) goto LAB_23e2e1e75;
            lVar13 = FUN_23e8bc2f0(plVar15,_DAT_23eead6b0);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if (lVar13 != 0) {
              plVar14[6] = lVar13;
              iVar9 = PySequence_Contains(plVar14,plVar12);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (iVar9 == -1) goto LAB_23e2e2cda;
              if (iVar9 == 1) {
                iVar9 = PySequence_Contains(plVar17,_DAT_23eead6b8);
                if (iVar9 != -1) {
                  if (iVar9 == 0) {
                    FUN_23e8bc550(plVar17,_DAT_23eead6b8);
                  }
                  goto LAB_23e2e2219;
                }
                plVar20 = (longlong *)0x0;
                goto LAB_23e2e28d7;
              }
              lVar13 = FUN_23e8f5ff0();
              plVar20 = (longlong *)0x0;
              if (lVar13 == 0) goto LAB_23e2e2289;
              plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
              plVar20 = (longlong *)0x0;
              if (plVar14 == (longlong *)0x0) goto LAB_23e2e260a;
              lVar13 = FUN_23e8bc2f0(plVar14,_DAT_23eead6c0);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (lVar13 == 0) {
LAB_23e2e2cea:
                plVar20 = (longlong *)0x0;
                goto LAB_23e2e260a;
              }
              lVar3 = *(longlong *)(param_1 + 0x10);
              plVar14 = *(longlong **)(lVar3 + 0xe28);
              if (plVar14 == (longlong *)0x0) {
                plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
              }
              else {
                lVar4 = plVar14[3];
                *(int *)(lVar3 + 0xec0) = *(int *)(lVar3 + 0xec0) + -1;
                *(longlong *)(lVar3 + 0xe28) = lVar4;
                *plVar14 = 1;
              }
              pcVar6 = _PyRuntime_exref;
              *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
              lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
              lVar4 = plVar14[-1];
              puVar5 = *(undefined8 **)(lVar3 + 8);
              *puVar5 = plVar14 + -2;
              plVar14[-2] = lVar3;
              plVar14[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
              *(longlong **)(lVar3 + 8) = plVar14 + -2;
              plVar14[3] = lVar13;
              lVar13 = FUN_23e8f5ff0();
              if (lVar13 == 0) {
LAB_23e2e2c63:
                plVar20 = (longlong *)0x0;
                goto LAB_23e2e1f68;
              }
              plVar15 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
              plVar20 = (longlong *)0x0;
              if (plVar15 == (longlong *)0x0) goto LAB_23e2e257a;
              lVar13 = FUN_23e8bc2f0(plVar15,_DAT_23eead6c8);
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              if (lVar13 != 0) {
                plVar14[4] = lVar13;
                lVar13 = FUN_23e8f5ff0();
                if (lVar13 == 0) goto LAB_23e2e2c63;
                plVar15 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
                plVar20 = (longlong *)0x0;
                if (plVar15 == (longlong *)0x0) goto LAB_23e2e257a;
                lVar13 = FUN_23e8bc2f0(plVar15,_DAT_23eead6d0);
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                if (lVar13 != 0) {
                  plVar14[5] = lVar13;
                  iVar9 = PySequence_Contains(plVar14,plVar12);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (iVar9 == -1) goto LAB_23e2e2cea;
                  if (iVar9 == 1) {
                    iVar9 = PySequence_Contains(plVar17,_DAT_23eead6d8);
                    if (iVar9 != -1) {
                      if (iVar9 == 0) {
                        FUN_23e8bc550(plVar17,_DAT_23eead6d8);
                      }
                      goto LAB_23e2e2219;
                    }
                    plVar20 = (longlong *)0x0;
                    goto LAB_23e2e29d2;
                  }
                  lVar13 = FUN_23e8f5ff0();
                  plVar20 = (longlong *)0x0;
                  if (lVar13 == 0) goto LAB_23e2e25ba;
                  plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
                  plVar20 = (longlong *)0x0;
                  if (plVar14 == (longlong *)0x0) goto LAB_23e2e292d;
                  plVar15 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23eead6e0);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  plVar20 = (longlong *)0x0;
                  if (plVar15 == (longlong *)0x0) goto LAB_23e2e296d;
                  iVar9 = FUN_23e912620(plVar12,plVar15);
                  *plVar15 = *plVar15 + -1;
                  uVar21 = extraout_XMM0_Qa_00;
                  if (*plVar15 == 0) {
                    uVar21 = (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  if (iVar9 == -1) {
LAB_23e2e2d9f:
                    plVar20 = (longlong *)0x0;
                    goto LAB_23e2e292d;
                  }
                  if (iVar9 != 1) {
                    lVar13 = FUN_23e8f5ff0(uVar21,_DAT_23eead6f8);
                    plVar20 = (longlong *)0x0;
                    if (lVar13 == 0) goto LAB_23e2e25ba;
                    plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
                    plVar20 = (longlong *)0x0;
                    if (plVar14 == (longlong *)0x0) goto LAB_23e2e292d;
                    plVar15 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23eead6e8);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    plVar20 = (longlong *)0x0;
                    if (plVar15 == (longlong *)0x0) goto LAB_23e2e296d;
                    iVar9 = FUN_23e912620(plVar12,plVar15);
                    *plVar15 = *plVar15 + -1;
                    uVar21 = extraout_XMM0_Qa_01;
                    if (*plVar15 == 0) {
                      uVar21 = (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    if (iVar9 == -1) goto LAB_23e2e2d9f;
                    if (iVar9 != 1) {
                      lVar13 = FUN_23e8f5ff0(uVar21,_DAT_23eead6f8);
                      plVar20 = (longlong *)0x0;
                      if (lVar13 == 0) goto LAB_23e2e25ba;
                      plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
                      plVar20 = (longlong *)0x0;
                      if (plVar14 == (longlong *)0x0) goto LAB_23e2e292d;
                      plVar15 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23eead6f0);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      plVar20 = (longlong *)0x0;
                      if (plVar15 == (longlong *)0x0) goto LAB_23e2e296d;
                      iVar9 = FUN_23e912620(plVar12,plVar15);
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        (**(code **)(plVar15[1] + 0x30))(plVar15);
                      }
                      if (iVar9 == -1) goto LAB_23e2e2d9f;
                      if (iVar9 != 1) {
                        FUN_23e8ba2b0(local_78,_DAT_23eead700);
                        if (((code *)local_78._0_8_ != _Py_NoneStruct_exref) &&
                           ((code *)local_78._0_8_ != (code *)0x0)) {
                          FUN_23e91b1b0(param_1,local_78,local_78 + 8,local_68);
                        }
                        uVar19 = 0xbf;
                        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_78._8_8_);
                        plVar20 = (longlong *)0x0;
                        plVar14 = local_68[0];
                        lVar13 = local_78._0_8_;
                        uVar21 = local_78._8_8_;
                        goto LAB_23e2e1240;
                      }
                    }
                  }
                  iVar9 = PySequence_Contains(plVar17,_DAT_23eead6f8);
                  if (iVar9 != -1) {
                    if (iVar9 == 0) {
                      FUN_23e8bc550(plVar17,_DAT_23eead6f8);
                    }
                    goto LAB_23e2e2219;
                  }
                  plVar20 = (longlong *)0x0;
                  goto LAB_23e2e2ca5;
                }
              }
              plVar20 = (longlong *)0x0;
              goto LAB_23e2e257a;
            }
          }
        }
        plVar20 = (longlong *)0x0;
        goto LAB_23e2e1e75;
      }
      iVar9 = PySequence_Contains(plVar17,_DAT_23eead688);
      if (iVar9 == -1) {
        plVar20 = (longlong *)0x0;
        goto LAB_23e2e22b6;
      }
      if (iVar9 == 0) {
        FUN_23e8bc550(plVar17,_DAT_23eead688);
      }
LAB_23e2e2219:
      lVar3 = *(longlong *)(param_1 + 0x10);
      if (((*(int *)(*(longlong *)(lVar3 + 0x28) + 0x160) != 0) || (*(int *)(lVar3 + 0x78) != 0)) &&
         ((iVar9 = Py_MakePendingCalls(), iVar9 < 0 &&
          (lVar13 = *(longlong *)(param_1 + 0x60), lVar13 != 0)))) {
        plVar15 = (longlong *)0x0;
        goto LAB_23e2e167f;
      }
      if (*(int *)(lVar3 + 0x68) == 0) {
        plVar14 = *(longlong **)(param_1 + 0x90);
      }
      else {
        PyEval_SaveThread();
        PyEval_AcquireThread(param_1);
        plVar14 = *(longlong **)(param_1 + 0x90);
      }
      if (plVar14 != (longlong *)0x0) {
        plVar15 = (longlong *)0x0;
        goto LAB_23e2e1604;
      }
      lVar13 = plVar11[1];
      plVar14 = plVar12;
      pcVar6 = *(code **)(lVar13 + 0xe0);
    }
    plVar20 = (longlong *)0x0;
  }
  else {
    lVar13 = plVar11[1];
    pcVar6 = *(code **)(lVar13 + 0xe0);
    plVar14 = (longlong *)0x0;
    plVar20 = (longlong *)0x0;
    while (pcVar6 != (code *)0x0) {
      plVar12 = (longlong *)(*pcVar6)(plVar11);
      if (plVar12 == (longlong *)0x0) goto LAB_23e2e0d33;
      if (plVar14 == (longlong *)0x0) {
        *plVar12 = *plVar12 + 1;
        lVar13 = FUN_23e8f5ff0();
      }
      else {
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        *plVar12 = *plVar12 + 1;
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        lVar13 = FUN_23e8f5ff0();
      }
      if (lVar13 == 0) goto LAB_23e2e11fa;
      plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
      if (plVar14 == (longlong *)0x0) goto LAB_23e2e1b35;
      lVar13 = FUN_23e8bc2f0(plVar14,_DAT_23eead670);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (lVar13 == 0) goto LAB_23e2e1b35;
      lVar3 = *(longlong *)(param_1 + 0x10);
      plVar14 = *(longlong **)(lVar3 + 0xe28);
      if (plVar14 == (longlong *)0x0) {
        plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
      }
      else {
        lVar4 = plVar14[3];
        *(int *)(lVar3 + 0xec0) = *(int *)(lVar3 + 0xec0) + -1;
        *(longlong *)(lVar3 + 0xe28) = lVar4;
        *plVar14 = 1;
      }
      pcVar6 = _PyRuntime_exref;
      *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
      lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
      lVar4 = plVar14[-1];
      puVar5 = *(undefined8 **)(lVar3 + 8);
      *puVar5 = plVar14 + -2;
      plVar14[-2] = lVar3;
      plVar14[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
      *(longlong **)(lVar3 + 8) = plVar14 + -2;
      plVar14[3] = lVar13;
      lVar13 = FUN_23e8f5ff0();
      if (lVar13 == 0) goto LAB_23e2e1565;
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
      if (plVar15 == (longlong *)0x0) goto LAB_23e2e1a95;
      lVar13 = FUN_23e8bc2f0(plVar15,_DAT_23eead678);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if (lVar13 == 0) goto LAB_23e2e1a95;
      plVar14[4] = lVar13;
      lVar13 = FUN_23e8f5ff0();
      if (lVar13 == 0) goto LAB_23e2e1565;
      plVar15 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
      if (plVar15 == (longlong *)0x0) goto LAB_23e2e1a95;
      lVar13 = FUN_23e8bc2f0(plVar15,_DAT_23eead680);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if (lVar13 == 0) goto LAB_23e2e1a95;
      plVar14[5] = lVar13;
      iVar9 = PySequence_Contains(plVar14,plVar12);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (iVar9 == -1) goto LAB_23e2e1b35;
      plVar15 = plVar20;
      if (iVar9 == 1) {
        iVar9 = PySequence_Contains(plVar17,_DAT_23eead688);
        if (iVar9 == -1) goto LAB_23e2e22b6;
        if (iVar9 == 0) {
          FUN_23e8bc550(plVar17,_DAT_23eead688);
        }
      }
      else {
        lVar13 = FUN_23e8f5ff0();
        if (lVar13 == 0) goto LAB_23e2e1e35;
        plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
        if (plVar14 == (longlong *)0x0) goto LAB_23e2e1f25;
        lVar13 = FUN_23e8bc2f0(plVar14,_DAT_23eead698);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if (lVar13 == 0) goto LAB_23e2e1f25;
        lVar3 = *(longlong *)(param_1 + 0x10);
        plVar14 = *(longlong **)(lVar3 + 0xe30);
        if (plVar14 == (longlong *)0x0) {
          plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
        }
        else {
          lVar4 = plVar14[3];
          *(int *)(lVar3 + 0xec4) = *(int *)(lVar3 + 0xec4) + -1;
          *(longlong *)(lVar3 + 0xe30) = lVar4;
          *plVar14 = 1;
        }
        pcVar6 = _PyRuntime_exref;
        plVar14[6] = 0;
        *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
        lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
        lVar4 = plVar14[-1];
        puVar5 = *(undefined8 **)(lVar3 + 8);
        *puVar5 = plVar14 + -2;
        plVar14[-2] = lVar3;
        plVar14[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
        *(longlong **)(lVar3 + 8) = plVar14 + -2;
        plVar14[3] = lVar13;
        lVar13 = FUN_23e8f5ff0();
        if (lVar13 == 0) goto LAB_23e2e1a35;
        plVar16 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
        if (plVar16 == (longlong *)0x0) goto LAB_23e2e1e75;
        lVar13 = FUN_23e8bc2f0(plVar16,_DAT_23eead6a0);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        if (lVar13 == 0) goto LAB_23e2e1e75;
        plVar14[4] = lVar13;
        lVar13 = FUN_23e8f5ff0();
        if (lVar13 == 0) goto LAB_23e2e1a35;
        plVar16 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
        if (plVar16 == (longlong *)0x0) goto LAB_23e2e1e75;
        lVar13 = FUN_23e8bc2f0(plVar16,_DAT_23eead6a8);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        if (lVar13 == 0) goto LAB_23e2e1e75;
        plVar14[5] = lVar13;
        lVar13 = FUN_23e8f5ff0();
        if (lVar13 == 0) goto LAB_23e2e1a35;
        plVar16 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
        if (plVar16 == (longlong *)0x0) goto LAB_23e2e1e75;
        lVar13 = FUN_23e8bc2f0(plVar16,_DAT_23eead6b0);
        *plVar16 = *plVar16 + -1;
        if (*plVar16 == 0) {
          (**(code **)(plVar16[1] + 0x30))(plVar16);
        }
        if (lVar13 == 0) goto LAB_23e2e1e75;
        plVar14[6] = lVar13;
        iVar9 = PySequence_Contains(plVar14,plVar12);
        *plVar14 = *plVar14 + -1;
        if (*plVar14 == 0) {
          (**(code **)(plVar14[1] + 0x30))(plVar14);
        }
        if (iVar9 == -1) goto LAB_23e2e1f25;
        if (iVar9 == 1) {
          iVar9 = PySequence_Contains(plVar17,_DAT_23eead6b8);
          if (iVar9 == -1) goto LAB_23e2e28d7;
          if (iVar9 == 0) {
            FUN_23e8bc550(plVar17,_DAT_23eead6b8);
          }
        }
        else {
          lVar13 = FUN_23e8f5ff0();
          if (lVar13 == 0) goto LAB_23e2e2289;
          plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
          if (plVar14 == (longlong *)0x0) goto LAB_23e2e260a;
          lVar13 = FUN_23e8bc2f0(plVar14,_DAT_23eead6c0);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (lVar13 == 0) goto LAB_23e2e260a;
          lVar3 = *(longlong *)(param_1 + 0x10);
          plVar14 = *(longlong **)(lVar3 + 0xe28);
          if (plVar14 == (longlong *)0x0) {
            plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
          }
          else {
            lVar4 = plVar14[3];
            *(int *)(lVar3 + 0xec0) = *(int *)(lVar3 + 0xec0) + -1;
            *(longlong *)(lVar3 + 0xe28) = lVar4;
            *plVar14 = 1;
          }
          pcVar6 = _PyRuntime_exref;
          *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
          lVar3 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
          lVar4 = plVar14[-1];
          puVar5 = *(undefined8 **)(lVar3 + 8);
          *puVar5 = plVar14 + -2;
          plVar14[-2] = lVar3;
          plVar14[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
          *(longlong **)(lVar3 + 8) = plVar14 + -2;
          plVar14[3] = lVar13;
          lVar13 = FUN_23e8f5ff0();
          if (lVar13 == 0) goto LAB_23e2e1f68;
          plVar16 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
          if (plVar16 == (longlong *)0x0) goto LAB_23e2e257a;
          lVar13 = FUN_23e8bc2f0(plVar16,_DAT_23eead6c8);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (lVar13 == 0) goto LAB_23e2e257a;
          plVar14[4] = lVar13;
          lVar13 = FUN_23e8f5ff0();
          if (lVar13 == 0) goto LAB_23e2e1f68;
          plVar16 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
          if (plVar16 == (longlong *)0x0) goto LAB_23e2e257a;
          lVar13 = FUN_23e8bc2f0(plVar16,_DAT_23eead6d0);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (lVar13 == 0) goto LAB_23e2e257a;
          plVar14[5] = lVar13;
          iVar9 = PySequence_Contains(plVar14,plVar12);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (iVar9 == -1) goto LAB_23e2e260a;
          if (iVar9 == 1) {
            iVar9 = PySequence_Contains(plVar17,_DAT_23eead6d8);
            if (iVar9 == -1) goto LAB_23e2e29d2;
            if (iVar9 == 0) {
              FUN_23e8bc550(plVar17,_DAT_23eead6d8);
            }
          }
          else {
            lVar13 = FUN_23e8f5ff0();
            if (lVar13 == 0) goto LAB_23e2e25ba;
            plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
            if (plVar14 == (longlong *)0x0) goto LAB_23e2e292d;
            plVar16 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23eead6e0);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            if (plVar16 == (longlong *)0x0) goto LAB_23e2e296d;
            iVar9 = FUN_23e912620(plVar12,plVar16);
            *plVar16 = *plVar16 + -1;
            uVar21 = extraout_XMM0_Qa;
            if (*plVar16 == 0) {
              uVar21 = (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            if (iVar9 == -1) goto LAB_23e2e292d;
            if (iVar9 != 1) {
              lVar13 = FUN_23e8f5ff0(uVar21,_DAT_23eead6f8);
              if (lVar13 == 0) goto LAB_23e2e25ba;
              plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
              if (plVar14 == (longlong *)0x0) goto LAB_23e2e292d;
              plVar16 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23eead6e8);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (plVar16 == (longlong *)0x0) goto LAB_23e2e296d;
              iVar9 = FUN_23e912620(plVar12,plVar16);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              if (iVar9 == -1) goto LAB_23e2e292d;
              if (iVar9 != 1) {
                lVar13 = FUN_23e8f5ff0();
                if (lVar13 == 0) goto LAB_23e2e25ba;
                plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
                if (plVar14 == (longlong *)0x0) goto LAB_23e2e292d;
                plVar16 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23eead6f0);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                if (plVar16 == (longlong *)0x0) goto LAB_23e2e296d;
                iVar9 = FUN_23e912620(plVar12,plVar16);
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                uVar21 = _DAT_23eead708;
                if (iVar9 == -1) goto LAB_23e2e292d;
                if (iVar9 != 1) {
                  *(undefined4 *)(plVar10 + 5) = 0xbf;
                  plVar15 = (longlong *)FUN_23e915840(param_1,plVar1,uVar21);
                  if (plVar15 == (longlong *)0x0) {
                    lVar13 = *(longlong *)(param_1 + 0x60);
                    plVar14 = *(longlong **)(param_1 + 0x70);
                    uVar19 = 0xbf;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar21 = *(undefined8 *)(param_1 + 0x68);
                  }
                  else {
                    if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
                      (**(code **)(plVar20[1] + 0x30))(plVar20);
                    }
                    iVar9 = FUN_23a35f020(plVar15);
                    if (iVar9 != -1) {
                      if (iVar9 != 0) {
                        iVar9 = PySequence_Contains(plVar18,plVar15);
                        if (iVar9 == -1) goto LAB_23e2e2cf2;
                        if (iVar9 == 0) {
                          FUN_23e8bc550(plVar18,plVar15);
                        }
                      }
                      goto LAB_23e2e0ca8;
                    }
LAB_23e2e2cf2:
                    lVar13 = *(longlong *)(param_1 + 0x60);
                    plVar14 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar19 = 0xc0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar20 = plVar15;
                    uVar21 = *(undefined8 *)(param_1 + 0x68);
                  }
                  goto LAB_23e2e1240;
                }
              }
            }
            iVar9 = PySequence_Contains(plVar17,_DAT_23eead6f8);
            if (iVar9 == -1) goto LAB_23e2e2ca5;
            if (iVar9 == 0) {
              FUN_23e8bc550(plVar17,_DAT_23eead6f8);
            }
          }
        }
      }
LAB_23e2e0ca8:
      lVar3 = *(longlong *)(param_1 + 0x10);
      if ((((*(int *)(*(longlong *)(lVar3 + 0x28) + 0x160) != 0) || (*(int *)(lVar3 + 0x78) != 0))
          && (iVar9 = Py_MakePendingCalls(), iVar9 < 0)) &&
         (lVar13 = *(longlong *)(param_1 + 0x60), lVar13 != 0)) goto LAB_23e2e167f;
      if (*(int *)(lVar3 + 0x68) == 0) {
        plVar14 = *(longlong **)(param_1 + 0x90);
      }
      else {
        PyEval_SaveThread();
        PyEval_AcquireThread(param_1);
        plVar14 = *(longlong **)(param_1 + 0x90);
      }
      if (plVar14 != (longlong *)0x0) goto LAB_23e2e1604;
      lVar13 = plVar11[1];
      plVar14 = plVar12;
      plVar20 = plVar15;
      pcVar6 = *(code **)(lVar13 + 0xe0);
    }
  }
  PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
               *(undefined8 *)(lVar13 + 0x18));
LAB_23e2e0d33:
  plVar12 = plVar14;
  cVar8 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
  if (cVar8 != '\0') {
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    plVar11 = (longlong *)FUN_23e8d64a0(*(undefined8 *)(_PyRuntime_exref + 0x1f8),plVar17,plVar18);
    iVar9 = FUN_23a35f020(plVar11);
    plVar14 = _DAT_23eead720;
    if (iVar9 == 1) {
      plVar14 = (longlong *)PyUnicode_Join(_DAT_23eead718,plVar11);
      if (plVar14 == (longlong *)0x0) {
        local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        local_68[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar19 = 0xc5;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e2e1286;
      }
    }
    else {
      *_DAT_23eead720 = *_DAT_23eead720 + 1;
    }
    lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
    plVar10 = *(longlong **)(lVar13 + 0x28);
    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
    plVar15 = (longlong *)plVar10[2];
    *(undefined4 *)(plVar10 + 8) = 0xffffffff;
    if (plVar15 != (longlong *)0x0) {
      plVar10[2] = 0;
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))();
      }
    }
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    plVar10[0xf] = 0;
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      (**(code **)(plVar17[1] + 0x30))(plVar17);
    }
    lVar13 = *plVar18;
    *plVar18 = lVar13 + -1;
    if (lVar13 + -1 == 0) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    lVar13 = *plVar1;
    *plVar1 = lVar13 + -1;
    if (lVar13 + -1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    lVar13 = *plVar2;
    *plVar2 = lVar13 + -1;
    if (lVar13 + -1 != 0) {
      return plVar14;
    }
    (**(code **)(plVar2[1] + 0x30))(plVar2);
    return plVar14;
  }
  plVar14 = *(longlong **)(param_1 + 0x70);
  lVar13 = *(longlong *)(param_1 + 0x60);
  uVar21 = *(undefined8 *)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x70) = 0;
  local_68[0] = (longlong *)0x0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  local_78 = (undefined1  [16])0x0;
  if (plVar12 != (longlong *)0x0) {
    uVar19 = 0xb0;
    goto LAB_23e2e1240;
  }
  plVar12 = (longlong *)0x0;
  uVar19 = 0xb0;
  goto LAB_23e2e125a;
LAB_23e2e11fa:
  FUN_23e915740(param_1,local_78,_DAT_23eead598);
  goto LAB_23e2e1211;
LAB_23e2e1565:
  FUN_23e915740(param_1,local_78,_DAT_23eead598);
  goto LAB_23e2e157c;
LAB_23e2e1a95:
  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
  local_68[0] = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2e157c:
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
LAB_23e2e1211:
  uVar19 = 0xb1;
  plVar14 = local_68[0];
  lVar13 = local_78._0_8_;
  uVar21 = local_78._8_8_;
  goto LAB_23e2e1240;
LAB_23e2e1b35:
  plVar14 = *(longlong **)(param_1 + 0x70);
  lVar13 = *(longlong *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar19 = 0xb1;
  uVar21 = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e2e1240;
LAB_23e2e22b6:
  plVar14 = *(longlong **)(param_1 + 0x70);
  lVar13 = *(longlong *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar19 = 0xb2;
  uVar21 = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e2e1240;
LAB_23e2e1e35:
  FUN_23e915740(param_1,local_78,_DAT_23eead598);
  goto LAB_23e2e1a5c;
LAB_23e2e1a35:
  FUN_23e915740(param_1,local_78,_DAT_23eead598);
  goto LAB_23e2e1a4c;
LAB_23e2e1e75:
  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
  local_68[0] = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2e1a4c:
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
LAB_23e2e1a5c:
  uVar19 = 0xb4;
  plVar14 = local_68[0];
  lVar13 = local_78._0_8_;
  uVar21 = local_78._8_8_;
  goto LAB_23e2e1240;
LAB_23e2e1f25:
  plVar14 = *(longlong **)(param_1 + 0x70);
  lVar13 = *(longlong *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar19 = 0xb4;
  uVar21 = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e2e1240;
LAB_23e2e2289:
  FUN_23e915740(param_1,local_78,_DAT_23eead598);
  goto LAB_23e2e1f99;
LAB_23e2e1f68:
  FUN_23e915740(param_1,local_78,_DAT_23eead598);
  goto LAB_23e2e1f89;
LAB_23e2e257a:
  local_78 = *(undefined1 (*) [16])(param_1 + 0x60);
  local_68[0] = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2e1f89:
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
LAB_23e2e1f99:
  uVar19 = 0xb7;
  plVar14 = local_68[0];
  lVar13 = local_78._0_8_;
  uVar21 = local_78._8_8_;
  goto LAB_23e2e1240;
LAB_23e2e260a:
  plVar14 = *(longlong **)(param_1 + 0x70);
  lVar13 = *(longlong *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar19 = 0xb7;
  uVar21 = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e2e1240;
LAB_23e2e29d2:
  plVar14 = *(longlong **)(param_1 + 0x70);
  lVar13 = *(longlong *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar19 = 0xb8;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar21 = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e2e1240;
LAB_23e2e25ba:
  uVar19 = 0xba;
  FUN_23e915740(param_1,local_78,_DAT_23eead598);
  plVar14 = local_68[0];
  lVar13 = local_78._0_8_;
  uVar21 = local_78._8_8_;
  goto LAB_23e2e1240;
LAB_23e2e296d:
  lVar13 = *(longlong *)(param_1 + 0x60);
  plVar14 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar19 = 0xba;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar21 = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e2e1240;
LAB_23e2e292d:
  plVar14 = *(longlong **)(param_1 + 0x70);
  lVar13 = *(longlong *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar19 = 0xba;
  uVar21 = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e2e1240;
LAB_23e2e2ca5:
  lVar13 = *(longlong *)(param_1 + 0x60);
  plVar14 = *(longlong **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar19 = 0xbb;
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar21 = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e2e1240;
LAB_23e2e28d7:
  plVar14 = *(longlong **)(param_1 + 0x70);
  lVar13 = *(longlong *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar19 = 0xb5;
  uVar21 = *(undefined8 *)(param_1 + 0x68);
  goto LAB_23e2e1240;
LAB_23e2e1604:
  plVar20 = *(longlong **)(param_1 + 0x60);
  plVar16 = *(longlong **)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x90) = 0;
  plVar7 = *(longlong **)(param_1 + 0x70);
  *(longlong **)(param_1 + 0x60) = plVar14;
  *plVar14 = *plVar14 + 1;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
    (**(code **)(plVar20[1] + 0x30))();
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  lVar13 = *(longlong *)(param_1 + 0x60);
LAB_23e2e167f:
  plVar14 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar19 = 0xb0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar20 = plVar15;
  uVar21 = *(undefined8 *)(param_1 + 0x68);
LAB_23e2e1240:
  local_68[0] = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
LAB_23e2e125a:
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar11 = (longlong *)0x0;
  local_78._8_8_ = uVar21;
  local_78._0_8_ = lVar13;
  local_68[0] = plVar14;
LAB_23e2e1286:
  plVar15 = local_68[0];
  plVar14 = DAT_23ed6a4f8;
  if (local_68[0] == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar15 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar15;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar14[2] = 0;
    plVar14[3] = (longlong)plVar10;
    *plVar10 = *plVar10 + 1;
    lVar13 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar13 = *(longlong *)(lVar13 + 0x10);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar19;
    lVar13 = *(longlong *)(lVar13 + 0x2e8);
    lVar3 = plVar14[-1];
    puVar5 = *(undefined8 **)(lVar13 + 8);
    *puVar5 = plVar14 + -2;
    plVar14[-2] = lVar13;
    plVar14[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar13 + 8) = plVar14 + -2;
    plVar15 = plVar14;
    if ((local_68[0] != (longlong *)0x0) && (*local_68[0] = *local_68[0] + -1, *local_68[0] == 0)) {
      (**(code **)(local_68[0][1] + 0x30))(local_68[0]);
    }
  }
  else if ((longlong *)local_68[0][3] != plVar10) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar14[3] = (longlong)plVar10;
    *plVar10 = *plVar10 + 1;
    lVar13 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar19;
    lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
    lVar3 = plVar14[-1];
    puVar5 = *(undefined8 **)(lVar13 + 8);
    *puVar5 = plVar14 + -2;
    plVar14[-2] = lVar13;
    plVar14[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar13 + 8) = plVar14 + -2;
    plVar14[2] = (longlong)plVar15;
    *plVar15 = *plVar15 + 1;
    plVar15 = plVar14;
    if ((local_68[0] != (longlong *)0x0) && (*local_68[0] = *local_68[0] + -1, *local_68[0] == 0)) {
      (**(code **)(local_68[0][1] + 0x30))(local_68[0]);
    }
  }
  local_68[0] = plVar15;
  FUN_23e8bba40(plVar10,"ooooooo",plVar1,plVar2,plVar17,plVar18,plVar12,plVar20,plVar11);
  if (_DAT_23eeb01d8 == plVar10) {
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    _DAT_23eeb01d8 = (longlong *)0x0;
  }
  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar13 + 0x28);
  plVar14 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar14 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
    plVar10[0xf] = 0;
    plVar10 = local_68[0];
    uVar21 = local_78._0_8_;
    uVar22 = local_78._8_8_;
  }
  else {
    plVar10[0xf] = 0;
    plVar10 = local_68[0];
    uVar21 = local_78._0_8_;
    uVar22 = local_78._8_8_;
  }
  local_68[0] = (longlong *)0x0;
  local_78 = (undefined1  [16])0x0;
  *plVar17 = *plVar17 + -1;
  if (*plVar17 == 0) {
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  lVar13 = *plVar18;
  *plVar18 = lVar13 + -1;
  if (lVar13 + -1 == 0) {
    (**(code **)(plVar18[1] + 0x30))();
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  local_78._8_8_ = uVar22;
  local_78._0_8_ = uVar21;
  lVar13 = *plVar1;
  *plVar1 = lVar13 + -1;
  local_68[0] = plVar10;
  if (lVar13 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar13 = *plVar2;
  *plVar2 = lVar13 + -1;
  if (lVar13 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_78._0_8_,local_78._8_8_,local_68[0]);
  return (longlong *)0x0;
}
