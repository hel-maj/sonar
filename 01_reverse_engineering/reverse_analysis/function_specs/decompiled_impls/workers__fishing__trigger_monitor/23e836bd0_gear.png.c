/* ===== 23e836bd0 workers.fishing.trigger_monitor:158 ===== */
/* ghidra_name=FUN_23e836bd0 entry=23e836bd0 size=12694 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e836bd0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 uVar13;
  longlong *plVar14;
  longlong *plVar15;
  int iVar16;
  undefined4 uVar17;
  longlong *in_R10;
  code *pcVar18;
  longlong **pplStack_88;
  code *pcStack_80;
  longlong *plStack_68;
  undefined8 uStack_60;
  
  lVar2 = DAT_23ed6cce8;
  plVar1 = (longlong *)*param_3;
  plVar7 = *(longlong **)(DAT_23ed6cce8 + 0x20);
  lVar9 = *(longlong *)(param_1 + 0x10);
  *plVar7 = *plVar7 + 1;
  if (*(int *)(lVar9 + 0x1410) == 0) {
    plVar14 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
    plVar7 = *(longlong **)(lVar2 + 0x20);
  }
  else {
    iVar16 = *(int *)(lVar9 + 0x1410) + -1;
    *(int *)(lVar9 + 0x1410) = iVar16;
    plVar14 = *(longlong **)(lVar9 + 0x1190 + (longlong)iVar16 * 8);
    *plVar14 = 1;
  }
  plVar6 = _DAT_23eede4d0;
  lVar9 = *(longlong *)(lVar2 + 0x28);
  plVar14[2] = 0;
  plVar14[3] = 1;
  plVar14[4] = (longlong)plVar7;
  plVar14[5] = lVar9;
  if (plVar6 == (longlong *)0x0) {
LAB_23e836c73:
    plVar6 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede4c8,DAT_23eede5a0,0x18);
    _DAT_23eede4d0 = plVar6;
  }
  else {
    lVar9 = *plVar6;
    if (1 < lVar9) {
      *plVar6 = lVar9 + -1;
      goto LAB_23e836c73;
    }
    if (plVar6[2] != 0) {
      *plVar6 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e836c73;
    }
  }
  lVar9 = *(longlong *)(param_1 + 0x38);
  lVar2 = *(longlong *)(lVar9 + 8);
  plVar6[0xf] = lVar2;
  *(longlong **)(lVar9 + 8) = plVar6 + 9;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  uVar13 = _DAT_23eedc120;
  *(undefined4 *)(plVar6 + 8) = 0;
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
  pcVar18 = _DAT_23eedc128;
  if (plVar7 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    uVar17 = 0xa3;
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = (longlong *)0x0;
    plVar7 = DAT_23ed6a4f8;
    goto joined_r0x00023e838073;
  }
  lVar9 = *(longlong *)(param_1 + 0x10);
  plVar12 = *(longlong **)(lVar9 + 0xe28);
  if (plVar12 == (longlong *)0x0) {
    plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
  }
  else {
    lVar2 = plVar12[3];
    *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
    *(longlong *)(lVar9 + 0xe28) = lVar2;
    *plVar12 = 1;
  }
  pcVar5 = _PyRuntime_exref;
  *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
  lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
  lVar2 = plVar12[-1];
  puVar3 = *(undefined8 **)(lVar9 + 8);
  *puVar3 = plVar12 + -2;
  plVar12[-2] = lVar9;
  plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
  *(longlong **)(lVar9 + 8) = plVar12 + -2;
  uVar13 = _DAT_23eedc0b0;
  *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
  plVar12[3] = (longlong)pcVar18;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
  uVar13 = DAT_23ed6cd28;
  if (plVar8 != (longlong *)0x0) {
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar10 == (longlong *)0x0) goto LAB_23e838760;
      *plVar10 = *plVar10 + 1;
      DAT_23ed6a4c0 = plVar10;
    }
    pplStack_88 = &plStack_68;
    uStack_60 = uVar13;
    plStack_68 = plVar8;
    lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplStack_88);
    *plVar8 = *plVar8 + -1;
    plVar10 = _DAT_23eedc130;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
      plVar10 = _DAT_23eedc130;
    }
    _DAT_23eedc130 = plVar10;
    if (lVar9 != 0) {
      plVar12[4] = lVar9;
      *plVar10 = *plVar10 + 1;
      plVar12[5] = (longlong)plVar10;
      pcStack_80 = PyUnicode_Join_exref;
      plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plVar8 == (longlong *)0x0) {
        uVar13 = *(undefined8 *)(param_1 + 0x60);
        uVar4 = *(undefined8 *)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          plVar10 = (longlong *)0x0;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
          uVar17 = 0xa3;
          plVar7 = DAT_23ed6a4f8;
        }
        else {
          plVar10 = (longlong *)0x0;
          uVar17 = 0xa3;
          plVar7 = DAT_23ed6a4f8;
        }
      }
      else {
        *(undefined4 *)(plVar6 + 5) = 0xa3;
        plVar10 = (longlong *)FUN_23e914090(param_1,plVar7,plVar8);
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        pcVar18 = PyDict_SetItem_exref;
        if (plVar10 == (longlong *)0x0) {
          uVar13 = *(undefined8 *)(param_1 + 0x60);
          uVar4 = *(undefined8 *)(param_1 + 0x68);
          plVar10 = (longlong *)0x0;
          plVar8 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar17 = 0xa3;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar7 = DAT_23ed6a4f8;
        }
        else {
          PyDict_SetItem(plVar14,_DAT_23eedc128,plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc120);
          plVar8 = _DAT_23eedc138;
          if (plVar7 == (longlong *)0x0) {
            uVar13 = *(undefined8 *)(param_1 + 0x60);
            uVar4 = *(undefined8 *)(param_1 + 0x68);
            uVar17 = 0xa4;
            plVar8 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar10 = (longlong *)0x0;
            plVar7 = DAT_23ed6a4f8;
          }
          else {
            lVar9 = *(longlong *)(param_1 + 0x10);
            plVar11 = *(longlong **)(lVar9 + 0xe28);
            if (plVar11 == (longlong *)0x0) {
              plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
            }
            else {
              lVar2 = plVar11[3];
              *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
              *(longlong *)(lVar9 + 0xe28) = lVar2;
              *plVar11 = 1;
            }
            pcVar5 = _PyRuntime_exref;
            *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
            lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
            lVar2 = plVar11[-1];
            puVar3 = *(undefined8 **)(lVar9 + 8);
            *puVar3 = plVar11 + -2;
            plVar11[-2] = lVar9;
            plVar11[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
            *(longlong **)(lVar9 + 8) = plVar11 + -2;
            uVar13 = _DAT_23eedc0b0;
            *plVar8 = *plVar8 + 1;
            plVar11[3] = (longlong)plVar8;
            plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
            uVar13 = DAT_23ed6cd28;
            if (plVar8 != (longlong *)0x0) {
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar12 = plVar11;
                in_R10 = plVar8;
                plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar10 == (longlong *)0x0) goto LAB_23e838760;
                *plVar10 = *plVar10 + 1;
                DAT_23ed6a4c0 = plVar10;
              }
              uStack_60 = uVar13;
              plStack_68 = plVar8;
              lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplStack_88);
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              if (lVar9 != 0) {
                plVar11[4] = lVar9;
                plVar8 = _DAT_23eedc130;
                *_DAT_23eedc130 = *_DAT_23eedc130 + 1;
                plVar11[5] = (longlong)plVar8;
                plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if (plVar8 == (longlong *)0x0) {
                  uVar13 = *(undefined8 *)(param_1 + 0x60);
                  uVar4 = *(undefined8 *)(param_1 + 0x68);
                  plVar8 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *plVar7 = *plVar7 + -1;
                  if (*plVar7 == 0) {
                    plVar10 = (longlong *)0x0;
                    (**(code **)(plVar7[1] + 0x30))(plVar7);
                    uVar17 = 0xa4;
                    plVar7 = DAT_23ed6a4f8;
                  }
                  else {
                    plVar10 = (longlong *)0x0;
                    uVar17 = 0xa4;
                    plVar7 = DAT_23ed6a4f8;
                  }
                }
                else {
                  *(undefined4 *)(plVar6 + 5) = 0xa4;
                  plVar10 = (longlong *)FUN_23e914090(param_1,plVar7);
                  *plVar7 = *plVar7 + -1;
                  if (*plVar7 == 0) {
                    (**(code **)(plVar7[1] + 0x30))(plVar7);
                  }
                  *plVar8 = *plVar8 + -1;
                  if (*plVar8 == 0) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  if (plVar10 == (longlong *)0x0) {
                    uVar13 = *(undefined8 *)(param_1 + 0x60);
                    uVar4 = *(undefined8 *)(param_1 + 0x68);
                    plVar10 = (longlong *)0x0;
                    plVar8 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar17 = 0xa4;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plVar7 = DAT_23ed6a4f8;
                  }
                  else {
                    PyDict_SetItem(plVar14,_DAT_23eedc138,plVar10);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc120);
                    plVar8 = _DAT_23eedc140;
                    if (plVar7 == (longlong *)0x0) {
                      uVar13 = *(undefined8 *)(param_1 + 0x60);
                      uVar4 = *(undefined8 *)(param_1 + 0x68);
                      uVar17 = 0xa5;
                      plVar8 = *(longlong **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plVar10 = (longlong *)0x0;
                      plVar7 = DAT_23ed6a4f8;
                    }
                    else {
                      lVar9 = *(longlong *)(param_1 + 0x10);
                      plVar11 = *(longlong **)(lVar9 + 0xe28);
                      if (plVar11 == (longlong *)0x0) {
                        plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                      }
                      else {
                        lVar2 = plVar11[3];
                        *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
                        *(longlong *)(lVar9 + 0xe28) = lVar2;
                        *plVar11 = 1;
                      }
                      pcVar5 = _PyRuntime_exref;
                      *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
                      lVar9 = *(longlong *)
                               (*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
                      lVar2 = plVar11[-1];
                      puVar3 = *(undefined8 **)(lVar9 + 8);
                      *puVar3 = plVar11 + -2;
                      plVar11[-2] = lVar9;
                      plVar11[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
                      *(longlong **)(lVar9 + 8) = plVar11 + -2;
                      uVar13 = _DAT_23eedc0b0;
                      *plVar8 = *plVar8 + 1;
                      plVar11[3] = (longlong)plVar8;
                      plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
                      if (plVar10 != (longlong *)0x0) {
                        plVar8 = plVar10;
                        uVar13 = DAT_23ed6cd28;
                        if (DAT_23ed6a4c0 == (longlong *)0x0) goto LAB_23e838778;
                        do {
                          plStack_68 = plVar8;
                          uStack_60 = uVar13;
                          lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplStack_88);
                          *plVar10 = *plVar10 + -1;
                          in_R10 = plVar10;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                            in_R10 = plVar10;
                          }
                          if (lVar9 == 0) break;
                          plVar11[4] = lVar9;
                          plVar8 = _DAT_23eedc130;
                          *_DAT_23eedc130 = *_DAT_23eedc130 + 1;
                          plVar11[5] = (longlong)plVar8;
                          plVar8 = (longlong *)(*pcStack_80)(DAT_23ed6cd28,plVar11);
                          *plVar11 = *plVar11 + -1;
                          if (*plVar11 == 0) {
                            (**(code **)(plVar11[1] + 0x30))(plVar11);
                          }
                          if (plVar8 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              plVar10 = (longlong *)0x0;
                              (**(code **)(plVar7[1] + 0x30))(plVar7);
                              uVar17 = 0xa5;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            else {
                              plVar10 = (longlong *)0x0;
                              uVar17 = 0xa5;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          *(undefined4 *)(plVar6 + 5) = 0xa5;
                          plVar10 = (longlong *)FUN_23e914090(param_1,plVar7);
                          *plVar7 = *plVar7 + -1;
                          if (*plVar7 == 0) {
                            (**(code **)(plVar7[1] + 0x30))(plVar7);
                          }
                          *plVar8 = *plVar8 + -1;
                          if (*plVar8 == 0) {
                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                          }
                          if (plVar10 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar10 = (longlong *)0x0;
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            uVar17 = 0xa5;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar7 = DAT_23ed6a4f8;
                            goto joined_r0x00023e838073;
                          }
                          (*pcVar18)(plVar14,_DAT_23eedc140,plVar10);
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc120);
                          if (plVar11 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar10 = (longlong *)0x0;
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            uVar17 = 0xa8;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar7 = DAT_23ed6a4f8;
                            goto joined_r0x00023e838073;
                          }
                          plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc0b0);
                          if (plVar7 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar17 = 0xa8;
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            lVar9 = *plVar11;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar11 = lVar9 + -1;
                            plVar10 = (longlong *)0x0;
                            plVar7 = DAT_23ed6a4f8;
                            if (lVar9 + -1 == 0) {
                              (**(code **)(plVar11[1] + 0x30))();
                              uVar17 = 0xa8;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          iVar16 = FUN_23a35f020(plVar7);
                          if (iVar16 == -1) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            lVar9 = *plVar11;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar11 = lVar9 + -1;
                            if (lVar9 + -1 == 0) {
                              (**(code **)(plVar11[1] + 0x30))();
                            }
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              plVar10 = (longlong *)0x0;
                              (**(code **)(plVar7[1] + 0x30))(plVar7);
                              uVar17 = 0xa8;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            else {
                              uVar17 = 0xa8;
                              plVar10 = (longlong *)0x0;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          *plVar7 = *plVar7 + -1;
                          if (*plVar7 == 0) {
                            (**(code **)(plVar7[1] + 0x30))(plVar7);
                          }
                          plVar10 = _DAT_23eedc150;
                          plVar8 = _DAT_23eedc148;
                          if (iVar16 != 0) {
                            lVar9 = *(longlong *)(param_1 + 0x10);
                            plVar7 = *(longlong **)(lVar9 + 0xe28);
                            if (plVar7 == (longlong *)0x0) {
                              plVar7 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                            }
                            else {
                              lVar2 = plVar7[3];
                              *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
                              *(longlong *)(lVar9 + 0xe28) = lVar2;
                              *plVar7 = 1;
                            }
                            pcVar5 = _PyRuntime_exref;
                            *(undefined1 (*) [16])(plVar7 + 4) = (undefined1  [16])0x0;
                            lVar9 = *(longlong *)
                                     (*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
                            lVar2 = plVar7[-1];
                            puVar3 = *(undefined8 **)(lVar9 + 8);
                            *puVar3 = plVar7 + -2;
                            plVar7[-2] = lVar9;
                            plVar7[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
                            *(longlong **)(lVar9 + 8) = plVar7 + -2;
                            uVar13 = _DAT_23eedc0b0;
                            *plVar8 = *plVar8 + 1;
                            plVar7[3] = (longlong)plVar8;
                            plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
                            uVar13 = DAT_23ed6cd28;
                            if (plVar8 != (longlong *)0x0) {
                              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                plVar12 = plVar8;
                                plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                if (plVar10 != (longlong *)0x0) {
                                  *plVar10 = *plVar10 + 1;
                                  DAT_23ed6a4c0 = plVar10;
                                  goto LAB_23e8388d0;
                                }
                                goto LAB_23e838760;
                              }
LAB_23e8388d0:
                              uStack_60 = uVar13;
                              plStack_68 = plVar8;
                              lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplStack_88);
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                (**(code **)(plVar8[1] + 0x30))(plVar8);
                              }
                              if (lVar9 != 0) {
                                plVar7[4] = lVar9;
                                plVar8 = _DAT_23eedc130;
                                *_DAT_23eedc130 = *_DAT_23eedc130 + 1;
                                plVar7[5] = (longlong)plVar8;
                                plVar10 = (longlong *)(*pcStack_80)(DAT_23ed6cd28,plVar7);
                                *plVar7 = *plVar7 + -1;
                                if (*plVar7 == 0) {
                                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                                }
                                if (plVar10 != (longlong *)0x0) goto LAB_23e837333;
                                uVar13 = *(undefined8 *)(param_1 + 0x60);
                                uVar4 = *(undefined8 *)(param_1 + 0x68);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                lVar9 = *plVar11;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *plVar11 = lVar9 + -1;
                                if (lVar9 + -1 == 0) {
                                  plVar10 = (longlong *)0x0;
                                  FUN_23a334bc0(plVar11);
                                  uVar17 = 0xa8;
                                  plVar7 = DAT_23ed6a4f8;
                                }
                                else {
                                  plVar10 = (longlong *)0x0;
                                  uVar17 = 0xa8;
                                  plVar7 = DAT_23ed6a4f8;
                                }
                                goto joined_r0x00023e838073;
                              }
                            }
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            lVar9 = *plVar11;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar11 = lVar9 + -1;
                            if (lVar9 + -1 == 0) {
                              (**(code **)(plVar11[1] + 0x30))();
                            }
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              plVar10 = (longlong *)0x0;
                              (**(code **)(plVar7[1] + 0x30))(plVar7);
                              uVar17 = 0xa8;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            else {
                              uVar17 = 0xa8;
                              plVar10 = (longlong *)0x0;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          *_DAT_23eedc150 = *_DAT_23eedc150 + 1;
LAB_23e837333:
                          *(undefined4 *)(plVar6 + 5) = 0xa8;
                          plVar7 = (longlong *)FUN_23e914090(param_1,plVar11);
                          lVar9 = *plVar11;
                          *plVar11 = lVar9 + -1;
                          if (lVar9 + -1 == 0) {
                            (**(code **)(plVar11[1] + 0x30))(plVar11);
                          }
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          if (plVar7 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            uVar17 = 0xa8;
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar10 = (longlong *)0x0;
                            plVar7 = DAT_23ed6a4f8;
                            goto joined_r0x00023e838073;
                          }
                          (*pcVar18)(plVar14,_DAT_23eedc148,plVar7);
                          *plVar7 = *plVar7 + -1;
                          if (*plVar7 == 0) {
                            (**(code **)(plVar7[1] + 0x30))(plVar7);
                          }
                          plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc120);
                          if (plVar11 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar10 = (longlong *)0x0;
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            uVar17 = 0xa9;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar7 = DAT_23ed6a4f8;
                            goto joined_r0x00023e838073;
                          }
                          plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc0b0);
                          if (plVar7 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar17 = 0xa9;
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            lVar9 = *plVar11;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar11 = lVar9 + -1;
                            plVar10 = (longlong *)0x0;
                            plVar7 = DAT_23ed6a4f8;
                            if (lVar9 + -1 == 0) {
                              (**(code **)(plVar11[1] + 0x30))();
                              uVar17 = 0xa9;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          iVar16 = FUN_23a35f020(plVar7);
                          if (iVar16 == -1) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            lVar9 = *plVar11;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar11 = lVar9 + -1;
                            if (lVar9 + -1 == 0) {
                              FUN_23a334bc0();
                            }
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              plVar10 = (longlong *)0x0;
                              FUN_23a334bc0(plVar7);
                              uVar17 = 0xa9;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            else {
                              uVar17 = 0xa9;
                              plVar10 = (longlong *)0x0;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          *plVar7 = *plVar7 + -1;
                          if (*plVar7 == 0) {
                            (**(code **)(plVar7[1] + 0x30))(plVar7);
                          }
                          plVar10 = _DAT_23eedc160;
                          plVar8 = _DAT_23eedc158;
                          if (iVar16 != 0) {
                            lVar9 = *(longlong *)(param_1 + 0x10);
                            plVar7 = *(longlong **)(lVar9 + 0xe28);
                            if (plVar7 == (longlong *)0x0) {
                              plVar7 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                            }
                            else {
                              lVar2 = plVar7[3];
                              *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
                              *(longlong *)(lVar9 + 0xe28) = lVar2;
                              *plVar7 = 1;
                            }
                            pcVar5 = _PyRuntime_exref;
                            *(undefined1 (*) [16])(plVar7 + 4) = (undefined1  [16])0x0;
                            lVar9 = *(longlong *)
                                     (*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
                            lVar2 = plVar7[-1];
                            puVar3 = *(undefined8 **)(lVar9 + 8);
                            *puVar3 = plVar7 + -2;
                            plVar7[-2] = lVar9;
                            plVar7[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
                            *(longlong **)(lVar9 + 8) = plVar7 + -2;
                            uVar13 = _DAT_23eedc0b0;
                            *plVar8 = *plVar8 + 1;
                            plVar7[3] = (longlong)plVar8;
                            plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
                            uVar13 = DAT_23ed6cd28;
                            if (plVar8 != (longlong *)0x0) {
                              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                plVar12 = plVar8;
                                plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                if (plVar10 == (longlong *)0x0) goto LAB_23e838760;
                                *plVar10 = *plVar10 + 1;
                                DAT_23ed6a4c0 = plVar10;
                              }
                              uStack_60 = uVar13;
                              plStack_68 = plVar8;
                              lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplStack_88);
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                (**(code **)(plVar8[1] + 0x30))(plVar8);
                              }
                              if (lVar9 != 0) {
                                plVar7[4] = lVar9;
                                plVar8 = _DAT_23eedc130;
                                *_DAT_23eedc130 = *_DAT_23eedc130 + 1;
                                plVar7[5] = (longlong)plVar8;
                                plVar10 = (longlong *)(*pcStack_80)(DAT_23ed6cd28,plVar7);
                                *plVar7 = *plVar7 + -1;
                                if (*plVar7 == 0) {
                                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                                }
                                if (plVar10 != (longlong *)0x0) goto LAB_23e83742b;
                                uVar13 = *(undefined8 *)(param_1 + 0x60);
                                uVar4 = *(undefined8 *)(param_1 + 0x68);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                lVar9 = *plVar11;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *plVar11 = lVar9 + -1;
                                if (lVar9 + -1 == 0) {
                                  plVar10 = (longlong *)0x0;
                                  FUN_23a334bc0(plVar11);
                                  uVar17 = 0xa9;
                                  plVar7 = DAT_23ed6a4f8;
                                }
                                else {
                                  plVar10 = (longlong *)0x0;
                                  uVar17 = 0xa9;
                                  plVar7 = DAT_23ed6a4f8;
                                }
                                goto joined_r0x00023e838073;
                              }
                            }
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            lVar9 = *plVar11;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar11 = lVar9 + -1;
                            if (lVar9 + -1 == 0) {
                              FUN_23a334bc0();
                            }
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              plVar10 = (longlong *)0x0;
                              FUN_23a334bc0(plVar7);
                              uVar17 = 0xa9;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            else {
                              uVar17 = 0xa9;
                              plVar10 = (longlong *)0x0;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          *_DAT_23eedc160 = *_DAT_23eedc160 + 1;
LAB_23e83742b:
                          *(undefined4 *)(plVar6 + 5) = 0xa9;
                          plVar7 = (longlong *)FUN_23e914090(param_1,plVar11);
                          lVar9 = *plVar11;
                          *plVar11 = lVar9 + -1;
                          plVar8 = in_R10;
                          if (lVar9 + -1 == 0) {
                            (**(code **)(plVar11[1] + 0x30))(plVar11);
                            plVar8 = in_R10;
                          }
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          if (plVar7 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            uVar17 = 0xa9;
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar10 = (longlong *)0x0;
                            plVar7 = DAT_23ed6a4f8;
                            goto joined_r0x00023e838073;
                          }
                          (*pcVar18)(plVar14,_DAT_23eedc168,plVar7);
                          *plVar7 = *plVar7 + -1;
                          if (*plVar7 == 0) {
                            (**(code **)(plVar7[1] + 0x30))(plVar7);
                          }
                          plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc120);
                          if (plVar7 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            uVar17 = 0xaa;
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar10 = (longlong *)0x0;
                            plVar7 = DAT_23ed6a4f8;
                            goto joined_r0x00023e838073;
                          }
                          plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc0b0);
                          if (plVar12 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              plVar10 = (longlong *)0x0;
                              FUN_23a334bc0(plVar7);
                              uVar17 = 0xaa;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            else {
                              plVar10 = (longlong *)0x0;
                              uVar17 = 0xaa;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          iVar16 = FUN_23a35f020(plVar12);
                          if (iVar16 == -1) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              FUN_23a334bc0(plVar7);
                            }
                            *plVar12 = *plVar12 + -1;
                            if (*plVar12 == 0) {
                              plVar10 = (longlong *)0x0;
                              FUN_23a334bc0(plVar12);
                              uVar17 = 0xaa;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            else {
                              uVar17 = 0xaa;
                              plVar10 = (longlong *)0x0;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
                          plVar12 = _DAT_23eedc178;
                          plVar10 = _DAT_23eedc170;
                          if (iVar16 != 0) {
                            lVar9 = *(longlong *)(param_1 + 0x10);
                            plVar11 = *(longlong **)(lVar9 + 0xe28);
                            if (plVar11 == (longlong *)0x0) {
                              plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                            }
                            else {
                              lVar2 = plVar11[3];
                              *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
                              *(longlong *)(lVar9 + 0xe28) = lVar2;
                              *plVar11 = 1;
                            }
                            pcVar5 = _PyRuntime_exref;
                            *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
                            lVar9 = *(longlong *)
                                     (*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
                            lVar2 = plVar11[-1];
                            puVar3 = *(undefined8 **)(lVar9 + 8);
                            *puVar3 = plVar11 + -2;
                            plVar11[-2] = lVar9;
                            plVar11[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
                            *(longlong **)(lVar9 + 8) = plVar11 + -2;
                            uVar13 = _DAT_23eedc0b0;
                            *plVar10 = *plVar10 + 1;
                            plVar11[3] = (longlong)plVar10;
                            plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
                            uVar13 = DAT_23ed6cd28;
                            if (plVar8 != (longlong *)0x0) {
                              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                plVar12 = plVar11;
                                in_R10 = plVar8;
                                plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                                if (plVar10 == (longlong *)0x0) goto LAB_23e838760;
                                *plVar10 = *plVar10 + 1;
                                DAT_23ed6a4c0 = plVar10;
                              }
                              uStack_60 = uVar13;
                              plStack_68 = plVar8;
                              lVar9 = FUN_23e94ed00(param_1);
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                (**(code **)(plVar8[1] + 0x30))(plVar8);
                              }
                              if (lVar9 != 0) {
                                plVar11[4] = lVar9;
                                plVar10 = _DAT_23eedc130;
                                *_DAT_23eedc130 = *_DAT_23eedc130 + 1;
                                plVar11[5] = (longlong)plVar10;
                                plVar12 = (longlong *)(*pcStack_80)(DAT_23ed6cd28,plVar11);
                                *plVar11 = *plVar11 + -1;
                                if (*plVar11 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (plVar12 != (longlong *)0x0) goto LAB_23e837529;
                                uVar13 = *(undefined8 *)(param_1 + 0x60);
                                uVar4 = *(undefined8 *)(param_1 + 0x68);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *plVar7 = *plVar7 + -1;
                                if (*plVar7 == 0) {
                                  plVar10 = (longlong *)0x0;
                                  FUN_23a334bc0(plVar7);
                                  uVar17 = 0xaa;
                                  plVar7 = DAT_23ed6a4f8;
                                }
                                else {
                                  plVar10 = (longlong *)0x0;
                                  uVar17 = 0xaa;
                                  plVar7 = DAT_23ed6a4f8;
                                }
                                goto joined_r0x00023e838073;
                              }
                            }
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              FUN_23a334bc0(plVar7);
                            }
                            *plVar11 = *plVar11 + -1;
                            if (*plVar11 == 0) {
                              plVar10 = (longlong *)0x0;
                              FUN_23a334bc0(plVar11);
                              uVar17 = 0xaa;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            else {
                              uVar17 = 0xaa;
                              plVar10 = (longlong *)0x0;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          *_DAT_23eedc178 = *_DAT_23eedc178 + 1;
LAB_23e837529:
                          *(undefined4 *)(plVar6 + 5) = 0xaa;
                          plVar10 = (longlong *)FUN_23e914090(param_1);
                          *plVar7 = *plVar7 + -1;
                          in_R10 = plVar8;
                          if (*plVar7 == 0) {
                            (**(code **)(plVar7[1] + 0x30))(plVar7);
                            in_R10 = plVar8;
                          }
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
                          if (plVar10 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plVar10 = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar17 = 0xaa;
                            plVar7 = DAT_23ed6a4f8;
                            goto joined_r0x00023e838073;
                          }
                          (*pcVar18)(plVar14,_DAT_23eedc180,plVar10);
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc120);
                          if (plVar7 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plVar10 = (longlong *)0x0;
                            uVar17 = 0xad;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar7 = DAT_23ed6a4f8;
                            goto joined_r0x00023e838073;
                          }
                          plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc0b0);
                          if (plVar12 == (longlong *)0x0) {
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar17 = 0xad;
                            lVar9 = *plVar7;
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar7 = lVar9 + -1;
                            plVar10 = (longlong *)0x0;
                            plVar7 = DAT_23ed6a4f8;
                            if (lVar9 + -1 == 0) {
                              FUN_23a334bc0();
                              uVar17 = 0xad;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          iVar16 = FUN_23a35f020(plVar12);
                          if (iVar16 == -1) {
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            lVar9 = *plVar7;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar7 = lVar9 + -1;
                            if (lVar9 + -1 == 0) {
                              FUN_23a334bc0();
                            }
                            *plVar12 = *plVar12 + -1;
                            if (*plVar12 == 0) {
                              plVar10 = (longlong *)0x0;
                              FUN_23a334bc0(plVar12);
                              uVar17 = 0xad;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            else {
                              uVar17 = 0xad;
                              plVar10 = (longlong *)0x0;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
                          plVar10 = _DAT_23eedc190;
                          plVar8 = _DAT_23eedc188;
                          if (iVar16 != 0) {
                            lVar9 = *(longlong *)(param_1 + 0x10);
                            plVar12 = *(longlong **)(lVar9 + 0xe28);
                            if (plVar12 == (longlong *)0x0) {
                              plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                            }
                            else {
                              lVar2 = plVar12[3];
                              *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
                              *(longlong *)(lVar9 + 0xe28) = lVar2;
                              *plVar12 = 1;
                            }
                            pcVar5 = _PyRuntime_exref;
                            *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
                            lVar9 = *(longlong *)
                                     (*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
                            lVar2 = plVar12[-1];
                            puVar3 = *(undefined8 **)(lVar9 + 8);
                            *puVar3 = plVar12 + -2;
                            plVar12[-2] = lVar9;
                            plVar12[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
                            *(longlong **)(lVar9 + 8) = plVar12 + -2;
                            uVar13 = _DAT_23eedc0b0;
                            *plVar8 = *plVar8 + 1;
                            plVar12[3] = (longlong)plVar8;
                            plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
                            if (plVar8 != (longlong *)0x0) {
                              lVar9 = FUN_23e94f9d0(param_1,plVar8,DAT_23ed6cd28);
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                FUN_23a334bc0(plVar8);
                              }
                              if (lVar9 != 0) {
                                plVar12[4] = lVar9;
                                plVar8 = _DAT_23eedc130;
                                *_DAT_23eedc130 = *_DAT_23eedc130 + 1;
                                plVar12[5] = (longlong)plVar8;
                                plVar10 = (longlong *)(*pcStack_80)(DAT_23ed6cd28,plVar12);
                                *plVar12 = *plVar12 + -1;
                                if (*plVar12 == 0) {
                                  FUN_23a334bc0(plVar12);
                                }
                                if (plVar10 != (longlong *)0x0) goto LAB_23e83762a;
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar13 = *(undefined8 *)(param_1 + 0x60);
                                uVar17 = 0xad;
                                lVar9 = *plVar7;
                                uVar4 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *plVar7 = lVar9 + -1;
                                plVar10 = (longlong *)0x0;
                                plVar7 = DAT_23ed6a4f8;
                                if (lVar9 + -1 == 0) {
                                  FUN_23a334bc0();
                                  uVar17 = 0xad;
                                  plVar7 = DAT_23ed6a4f8;
                                }
                                goto joined_r0x00023e838073;
                              }
                            }
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            lVar9 = *plVar7;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar7 = lVar9 + -1;
                            if (lVar9 + -1 == 0) {
                              FUN_23a334bc0(plVar7);
                            }
                            *plVar12 = *plVar12 + -1;
                            if (*plVar12 == 0) {
                              plVar10 = (longlong *)0x0;
                              FUN_23a334bc0(plVar12);
                              uVar17 = 0xad;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            else {
                              uVar17 = 0xad;
                              plVar10 = (longlong *)0x0;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e838073;
                          }
                          *_DAT_23eedc190 = *_DAT_23eedc190 + 1;
LAB_23e83762a:
                          *(undefined4 *)(plVar6 + 5) = 0xad;
                          plVar8 = (longlong *)FUN_23e914090(param_1,plVar7,plVar10);
                          lVar9 = *plVar7;
                          *plVar7 = lVar9 + -1;
                          if (lVar9 + -1 == 0) {
                            (**(code **)(plVar7[1] + 0x30))(plVar7);
                          }
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          if (plVar8 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            uVar17 = 0xad;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar10 = (longlong *)0x0;
                            plVar7 = DAT_23ed6a4f8;
                            goto joined_r0x00023e838073;
                          }
                          (*pcVar18)(plVar14,_DAT_23eedc198);
                          *plVar8 = *plVar8 + -1;
                          if (*plVar8 == 0) {
                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                          }
                          plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc120);
                          plVar7 = _DAT_23eedc1a0;
                          if (plVar10 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plVar10 = (longlong *)0x0;
                            uVar17 = 0xb0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar7 = DAT_23ed6a4f8;
                            goto joined_r0x00023e838073;
                          }
                          lVar9 = *(longlong *)(param_1 + 0x10);
                          plVar11 = *(longlong **)(lVar9 + 0xe28);
                          if (plVar11 == (longlong *)0x0) {
                            plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                          }
                          else {
                            lVar2 = plVar11[3];
                            *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
                            *(longlong *)(lVar9 + 0xe28) = lVar2;
                            *plVar11 = 1;
                          }
                          pcVar5 = _PyRuntime_exref;
                          *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
                          lVar9 = *(longlong *)
                                   (*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
                          lVar2 = plVar11[-1];
                          puVar3 = *(undefined8 **)(lVar9 + 8);
                          *puVar3 = plVar11 + -2;
                          plVar11[-2] = lVar9;
                          plVar11[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
                          *(longlong **)(lVar9 + 8) = plVar11 + -2;
                          uVar13 = _DAT_23eedc0b0;
                          *plVar7 = *plVar7 + 1;
                          plVar11[3] = (longlong)plVar7;
                          plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
                          uVar13 = DAT_23ed6cd28;
                          if (plVar7 == (longlong *)0x0) goto LAB_23e83936e;
                          if (DAT_23ed6a4c0 != (longlong *)0x0) goto LAB_23e8377a1;
                          plVar12 = plVar11;
                          plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                          plVar8 = plVar7;
                          if (plVar15 != (longlong *)0x0) goto code_r0x00023e839511;
LAB_23e838760:
                          do {
                            PyErr_PrintEx(0);
                            Py_Exit(1);
                            plVar11 = plVar12;
                            plVar10 = in_R10;
LAB_23e838778:
                            plVar12 = plVar11;
                            in_R10 = plVar10;
                            plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                          } while (plVar15 == (longlong *)0x0);
                          *plVar15 = *plVar15 + 1;
                          DAT_23ed6a4c0 = plVar15;
                        } while( true );
                      }
                      uVar13 = *(undefined8 *)(param_1 + 0x60);
                      uVar4 = *(undefined8 *)(param_1 + 0x68);
                      plVar8 = *(longlong **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *plVar7 = *plVar7 + -1;
                      if (*plVar7 == 0) {
                        (**(code **)(plVar7[1] + 0x30))(plVar7);
                      }
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        plVar10 = (longlong *)0x0;
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                        uVar17 = 0xa5;
                        plVar7 = DAT_23ed6a4f8;
                      }
                      else {
                        uVar17 = 0xa5;
                        plVar10 = (longlong *)0x0;
                        plVar7 = DAT_23ed6a4f8;
                      }
                    }
                  }
                }
                goto joined_r0x00023e838073;
              }
            }
            uVar13 = *(undefined8 *)(param_1 + 0x60);
            uVar4 = *(undefined8 *)(param_1 + 0x68);
            plVar8 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              plVar10 = (longlong *)0x0;
              (**(code **)(plVar11[1] + 0x30))(plVar11);
              uVar17 = 0xa4;
              plVar7 = DAT_23ed6a4f8;
            }
            else {
              uVar17 = 0xa4;
              plVar10 = (longlong *)0x0;
              plVar7 = DAT_23ed6a4f8;
            }
          }
        }
      }
      goto joined_r0x00023e838073;
    }
  }
  uVar13 = *(undefined8 *)(param_1 + 0x60);
  uVar4 = *(undefined8 *)(param_1 + 0x68);
  plVar8 = *(longlong **)(param_1 + 0x70);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    plVar10 = (longlong *)0x0;
    (**(code **)(plVar12[1] + 0x30))(plVar12);
    uVar17 = 0xa3;
    plVar7 = DAT_23ed6a4f8;
  }
  else {
    uVar17 = 0xa3;
    plVar10 = (longlong *)0x0;
    plVar7 = DAT_23ed6a4f8;
  }
joined_r0x00023e838073:
  DAT_23ed6a4f8 = plVar7;
  if (plVar8 == (longlong *)0x0) {
    if (plVar7 == (longlong *)0x0) {
      plVar7 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar7;
      *plVar7 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar7[2] = 0;
    plVar7[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar9 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)((longlong)plVar7 + 0x24) = uVar17;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)(plVar7 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar2 = plVar7[-1];
    puVar3 = *(undefined8 **)(lVar9 + 8);
    *puVar3 = plVar7 + -2;
    plVar7[-2] = lVar9;
    plVar7[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
    *(longlong **)(lVar9 + 8) = plVar7 + -2;
    plVar12 = plVar7;
  }
  else {
    plVar12 = plVar8;
    if ((longlong *)plVar8[3] != plVar6) {
      if (plVar7 == (longlong *)0x0) {
        plVar7 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar7;
        *plVar7 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar7[3] = (longlong)plVar6;
      *plVar6 = *plVar6 + 1;
      *(undefined4 *)((longlong)plVar7 + 0x24) = uVar17;
      pcVar18 = _PyRuntime_exref;
      *(undefined4 *)(plVar7 + 4) = 0xffffffff;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
      lVar2 = plVar7[-1];
      puVar3 = *(undefined8 **)(lVar9 + 8);
      *puVar3 = plVar7 + -2;
      plVar7[-2] = lVar9;
      plVar7[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar3;
      lVar2 = *plVar8;
      *(longlong **)(lVar9 + 8) = plVar7 + -2;
      plVar7[2] = (longlong)plVar8;
      plVar12 = plVar7;
      if (lVar2 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  FUN_23e8bba40(plVar6,&DAT_23ec5e2be,plVar1,plVar14,plVar10);
  if (_DAT_23eede4d0 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    _DAT_23eede4d0 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar9 + 0x28);
  plVar6 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar6 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar13,uVar4,plVar12);
  return (longlong *)0x0;
code_r0x00023e839511:
  *plVar15 = *plVar15 + 1;
  DAT_23ed6a4c0 = plVar15;
LAB_23e8377a1:
  uStack_60 = uVar13;
  plStack_68 = plVar7;
  lVar9 = FUN_23e94ed00(param_1);
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    FUN_23a334bc0(plVar7);
  }
  if (lVar9 == 0) {
LAB_23e83936e:
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    lVar9 = *plVar10;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar10 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      FUN_23a334bc0(plVar10);
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      plVar10 = (longlong *)0x0;
      FUN_23a334bc0(plVar11);
      uVar17 = 0xb0;
      plVar7 = DAT_23ed6a4f8;
    }
    else {
      uVar17 = 0xb0;
      plVar10 = (longlong *)0x0;
      plVar7 = DAT_23ed6a4f8;
    }
    goto joined_r0x00023e838073;
  }
  plVar11[4] = lVar9;
  plVar7 = _DAT_23eedc130;
  *_DAT_23eedc130 = *_DAT_23eedc130 + 1;
  plVar11[5] = (longlong)plVar7;
  plVar7 = (longlong *)(*pcStack_80)(DAT_23ed6cd28,plVar11);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    FUN_23a334bc0(plVar11);
  }
  if (plVar7 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar17 = 0xb0;
    lVar9 = *plVar10;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar10 = lVar9 + -1;
    plVar10 = (longlong *)0x0;
    plVar7 = DAT_23ed6a4f8;
    if (lVar9 + -1 == 0) {
      FUN_23a334bc0();
      uVar17 = 0xb0;
      plVar7 = DAT_23ed6a4f8;
    }
    goto joined_r0x00023e838073;
  }
  *(undefined4 *)(plVar6 + 5) = 0xb0;
  plVar8 = (longlong *)FUN_23e914090(param_1,plVar10,plVar7);
  lVar9 = *plVar10;
  *plVar10 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    FUN_23a334bc0();
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    FUN_23a334bc0();
  }
  if (plVar8 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    uVar17 = 0xb0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar7 = DAT_23ed6a4f8;
    goto joined_r0x00023e838073;
  }
  (*pcVar18)(plVar14,_DAT_23eedc1a0);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    FUN_23a334bc0(plVar8);
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar1);
  if (plVar12 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar17 = 0xb1;
    plVar7 = DAT_23ed6a4f8;
    goto joined_r0x00023e838073;
  }
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc0b0);
  if (plVar7 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar17 = 0xb1;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar12 = *plVar12 + -1;
    plVar10 = (longlong *)0x0;
    plVar7 = DAT_23ed6a4f8;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
      uVar17 = 0xb1;
      plVar7 = DAT_23ed6a4f8;
    }
    goto joined_r0x00023e838073;
  }
  iVar16 = FUN_23a35f020(plVar7);
  if (iVar16 == -1) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      plVar10 = (longlong *)0x0;
      FUN_23a334bc0(plVar7);
      uVar17 = 0xb1;
      plVar7 = DAT_23ed6a4f8;
    }
    else {
      uVar17 = 0xb1;
      plVar10 = (longlong *)0x0;
      plVar7 = DAT_23ed6a4f8;
    }
    goto joined_r0x00023e838073;
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    FUN_23a334bc0(plVar7);
  }
  plVar8 = _DAT_23eedc1b0;
  plVar7 = _DAT_23eedc1a8;
  if (iVar16 != 0) {
    plVar11 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
    *plVar7 = *plVar7 + 1;
    uVar13 = _DAT_23eedc0b0;
    plVar11[3] = (longlong)plVar7;
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
    if (plVar7 != (longlong *)0x0) {
      lVar9 = FUN_23e94f9d0(param_1,plVar7,DAT_23ed6cd28);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        FUN_23a334bc0(plVar7);
      }
      if (lVar9 != 0) {
        plVar11[4] = lVar9;
        plVar7 = _DAT_23eedc130;
        *_DAT_23eedc130 = *_DAT_23eedc130 + 1;
        plVar11[5] = (longlong)plVar7;
        plVar8 = (longlong *)(*pcStack_80)(DAT_23ed6cd28,plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          FUN_23a334bc0(plVar11);
        }
        if (plVar8 == (longlong *)0x0) {
          uVar13 = *(undefined8 *)(param_1 + 0x60);
          uVar4 = *(undefined8 *)(param_1 + 0x68);
          plVar8 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar17 = 0xb1;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar12 = *plVar12 + -1;
          plVar10 = (longlong *)0x0;
          plVar7 = DAT_23ed6a4f8;
          if (*plVar12 == 0) {
            FUN_23a334bc0(plVar12);
            uVar17 = 0xb1;
            plVar7 = DAT_23ed6a4f8;
          }
          goto joined_r0x00023e838073;
        }
        goto LAB_23e83793b;
      }
    }
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      plVar10 = (longlong *)0x0;
      FUN_23a334bc0(plVar11);
      uVar17 = 0xb1;
      plVar7 = DAT_23ed6a4f8;
    }
    else {
      uVar17 = 0xb1;
      plVar10 = (longlong *)0x0;
      plVar7 = DAT_23ed6a4f8;
    }
    goto joined_r0x00023e838073;
  }
  *_DAT_23eedc1b0 = *_DAT_23eedc1b0 + 1;
LAB_23e83793b:
  *(undefined4 *)(plVar6 + 5) = 0xb1;
  plVar7 = (longlong *)FUN_23e914090(param_1,plVar12,plVar8);
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    FUN_23a334bc0(plVar12);
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    FUN_23a334bc0(plVar8);
  }
  if (plVar7 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    uVar17 = 0xb1;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar7 = DAT_23ed6a4f8;
    goto joined_r0x00023e838073;
  }
  (*pcVar18)(plVar14,_DAT_23eedc1b8);
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    FUN_23a334bc0(plVar7);
  }
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc120);
  if (plVar12 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar17 = 0xb2;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar10 = (longlong *)0x0;
    plVar7 = DAT_23ed6a4f8;
    goto joined_r0x00023e838073;
  }
  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc0b0);
  if (plVar7 == (longlong *)0x0) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar17 = 0xb2;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar12 = *plVar12 + -1;
    plVar10 = (longlong *)0x0;
    plVar7 = DAT_23ed6a4f8;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
      uVar17 = 0xb2;
      plVar7 = DAT_23ed6a4f8;
    }
    goto joined_r0x00023e838073;
  }
  iVar16 = FUN_23a35f020(plVar7);
  if (iVar16 == -1) {
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      plVar10 = (longlong *)0x0;
      FUN_23a334bc0(plVar7);
      uVar17 = 0xb2;
      plVar7 = DAT_23ed6a4f8;
    }
    else {
      uVar17 = 0xb2;
      plVar10 = (longlong *)0x0;
      plVar7 = DAT_23ed6a4f8;
    }
    goto joined_r0x00023e838073;
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    FUN_23a334bc0(plVar7);
  }
  plVar8 = _DAT_23eedc1c8;
  plVar7 = _DAT_23eedc1c0;
  if (iVar16 == 0) {
    *_DAT_23eedc1c8 = *_DAT_23eedc1c8 + 1;
LAB_23e837a48:
    *(undefined4 *)(plVar6 + 5) = 0xb2;
    plVar7 = (longlong *)FUN_23e914090(param_1,plVar12,plVar8);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      FUN_23a334bc0(plVar8);
    }
    if (plVar7 == (longlong *)0x0) {
      uVar13 = *(undefined8 *)(param_1 + 0x60);
      uVar4 = *(undefined8 *)(param_1 + 0x68);
      plVar8 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar17 = 0xb2;
      plVar7 = DAT_23ed6a4f8;
    }
    else {
      (*pcVar18)(plVar14,_DAT_23eedc1d0);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        FUN_23a334bc0(plVar7);
      }
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc120);
      plVar7 = _DAT_23eedc1d8;
      if (plVar12 == (longlong *)0x0) {
        uVar13 = *(undefined8 *)(param_1 + 0x60);
        uVar4 = *(undefined8 *)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = (longlong *)0x0;
        uVar17 = 0xb5;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar7 = DAT_23ed6a4f8;
      }
      else {
        plVar11 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
        *plVar7 = *plVar7 + 1;
        uVar13 = _DAT_23eedc0b0;
        plVar11[3] = (longlong)plVar7;
        plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
        if (plVar7 != (longlong *)0x0) {
          lVar9 = FUN_23e94f9d0(param_1,plVar7,DAT_23ed6cd28);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            FUN_23a334bc0(plVar7);
          }
          if (lVar9 != 0) {
            plVar11[4] = lVar9;
            plVar7 = _DAT_23eedc130;
            *_DAT_23eedc130 = *_DAT_23eedc130 + 1;
            plVar11[5] = (longlong)plVar7;
            plVar7 = (longlong *)(*pcStack_80)(DAT_23ed6cd28,plVar11);
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0(plVar11);
            }
            if (plVar7 == (longlong *)0x0) {
              uVar13 = *(undefined8 *)(param_1 + 0x60);
              uVar4 = *(undefined8 *)(param_1 + 0x68);
              plVar8 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar17 = 0xb5;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar12 = *plVar12 + -1;
              plVar10 = (longlong *)0x0;
              plVar7 = DAT_23ed6a4f8;
              if (*plVar12 == 0) {
                FUN_23a334bc0(plVar12);
                uVar17 = 0xb5;
                plVar7 = DAT_23ed6a4f8;
              }
            }
            else {
              *(undefined4 *)(plVar6 + 5) = 0xb5;
              plVar8 = (longlong *)FUN_23e914090(param_1,plVar12,plVar7);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                FUN_23a334bc0(plVar12);
              }
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                FUN_23a334bc0(plVar7);
              }
              if (plVar8 == (longlong *)0x0) {
                uVar13 = *(undefined8 *)(param_1 + 0x60);
                uVar4 = *(undefined8 *)(param_1 + 0x68);
                plVar8 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar10 = (longlong *)0x0;
                uVar17 = 0xb5;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plVar7 = DAT_23ed6a4f8;
              }
              else {
                (*pcVar18)(plVar14,_DAT_23eedc1d8);
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  FUN_23a334bc0(plVar8);
                }
                plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,_DAT_23eedc120);
                plVar7 = _DAT_23eedc1e0;
                if (plVar12 == (longlong *)0x0) {
                  uVar13 = *(undefined8 *)(param_1 + 0x60);
                  uVar4 = *(undefined8 *)(param_1 + 0x68);
                  plVar8 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar10 = (longlong *)0x0;
                  uVar17 = 0xb6;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plVar7 = DAT_23ed6a4f8;
                }
                else {
                  plVar11 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
                  *plVar7 = *plVar7 + 1;
                  uVar13 = _DAT_23eedc0b0;
                  plVar11[3] = (longlong)plVar7;
                  plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
                  if (plVar7 != (longlong *)0x0) {
                    lVar9 = FUN_23e94f9d0(param_1,plVar7,DAT_23ed6cd28);
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      FUN_23a334bc0(plVar7);
                    }
                    if (lVar9 != 0) {
                      plVar11[4] = lVar9;
                      plVar7 = _DAT_23eedc130;
                      *_DAT_23eedc130 = *_DAT_23eedc130 + 1;
                      plVar11[5] = (longlong)plVar7;
                      plVar7 = (longlong *)(*pcStack_80)(DAT_23ed6cd28,plVar11);
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        FUN_23a334bc0(plVar11);
                      }
                      if (plVar7 == (longlong *)0x0) {
                        uVar13 = *(undefined8 *)(param_1 + 0x60);
                        uVar4 = *(undefined8 *)(param_1 + 0x68);
                        plVar8 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        uVar17 = 0xb6;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *plVar12 = *plVar12 + -1;
                        plVar10 = (longlong *)0x0;
                        plVar7 = DAT_23ed6a4f8;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0(plVar12);
                          uVar17 = 0xb6;
                          plVar7 = DAT_23ed6a4f8;
                        }
                      }
                      else {
                        *(undefined4 *)(plVar6 + 5) = 0xb6;
                        plVar8 = (longlong *)FUN_23e914090(param_1,plVar12,plVar7);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0(plVar12);
                        }
                        *plVar7 = *plVar7 + -1;
                        if (*plVar7 == 0) {
                          FUN_23a334bc0(plVar7);
                        }
                        if (plVar8 == (longlong *)0x0) {
                          uVar13 = *(undefined8 *)(param_1 + 0x60);
                          uVar4 = *(undefined8 *)(param_1 + 0x68);
                          plVar8 = *(longlong **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar10 = (longlong *)0x0;
                          uVar17 = 0xb6;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          plVar7 = DAT_23ed6a4f8;
                        }
                        else {
                          (*pcVar18)(plVar14,_DAT_23eedc1e0);
                          *plVar8 = *plVar8 + -1;
                          if (*plVar8 == 0) {
                            FUN_23a334bc0(plVar8);
                          }
                          plVar7 = (longlong *)FUN_23e94b5b0(plVar14);
                          plVar8 = (longlong *)FUN_23ebf7180(plVar7);
                          *plVar7 = *plVar7 + -1;
                          if (*plVar7 == 0) {
                            FUN_23a334bc0();
                          }
                          if (plVar8 == (longlong *)0x0) {
                            uVar13 = *(undefined8 *)(param_1 + 0x60);
                            uVar4 = *(undefined8 *)(param_1 + 0x68);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            uVar17 = 0xb9;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            plVar10 = (longlong *)0x0;
                            plVar7 = DAT_23ed6a4f8;
                          }
                          else {
                            plStack_68 = (longlong *)FUN_23e8d6950(plVar8);
                            plVar7 = (longlong *)
                                     FUN_23e91ecd0(FUN_23e839e10,DAT_23eede5a0,_DAT_23eedc200,
                                                   _DAT_23eedc208,DAT_23eede4c0,pplStack_88,1,0x78);
                            *plVar8 = *plVar8 + -1;
                            if (*plVar8 == 0) {
                              FUN_23a334bc0(plVar8);
                            }
                            plVar10 = (longlong *)FUN_23e931a30(param_1,plVar7);
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              FUN_23a334bc0(plVar7);
                            }
                            if (plVar10 == (longlong *)0x0) {
                              uVar13 = *(undefined8 *)(param_1 + 0x60);
                              uVar4 = *(undefined8 *)(param_1 + 0x68);
                              plVar8 = *(longlong **)(param_1 + 0x70);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              uVar17 = 0xb9;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              plVar7 = DAT_23ed6a4f8;
                            }
                            else {
                              uVar13 = FUN_23a3a0d40(DAT_23ed6cf28);
                              plVar7 = _DAT_23eedc1e8;
                              plVar12 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),5)
                              ;
                              *plVar7 = *plVar7 + 1;
                              plVar12[3] = (longlong)plVar7;
                              lVar9 = FUN_23e94f9d0(param_1,plVar10,DAT_23ed6cd28);
                              if (lVar9 != 0) {
                                plVar12[4] = lVar9;
                                plVar7 = DAT_23ed6cea0;
                                *DAT_23ed6cea0 = *DAT_23ed6cea0 + 1;
                                plVar12[5] = (longlong)plVar7;
                                plVar7 = (longlong *)FUN_23e8bd600(param_1,plVar14);
                                lVar9 = FUN_23e94f9d0(param_1,plVar7,DAT_23ed6cd28);
                                *plVar7 = *plVar7 + -1;
                                if (*plVar7 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (lVar9 != 0) {
                                  plVar12[6] = lVar9;
                                  plVar7 = _DAT_23eedc1f0;
                                  *_DAT_23eedc1f0 = *_DAT_23eedc1f0 + 1;
                                  plVar12[7] = (longlong)plVar7;
                                  plVar7 = (longlong *)(*pcStack_80)(DAT_23ed6cd28);
                                  *plVar12 = *plVar12 + -1;
                                  if (*plVar12 == 0) {
                                    FUN_23a334bc0(plVar12);
                                  }
                                  if (plVar7 == (longlong *)0x0) {
                                    uVar13 = *(undefined8 *)(param_1 + 0x60);
                                    uVar4 = *(undefined8 *)(param_1 + 0x68);
                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    uVar17 = 0xba;
                                    plVar7 = DAT_23ed6a4f8;
                                  }
                                  else {
                                    *(undefined4 *)(plVar6 + 5) = 0xba;
                                    plVar8 = (longlong *)FUN_23e914090(param_1,uVar13,plVar7);
                                    *plVar7 = *plVar7 + -1;
                                    if (*plVar7 == 0) {
                                      FUN_23a334bc0(plVar7);
                                    }
                                    if (plVar8 != (longlong *)0x0) {
                                      *plVar8 = *plVar8 + -1;
                                      if (*plVar8 == 0) {
                                        FUN_23a334bc0(plVar8);
                                      }
                                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                      if (*plVar14 == 0) {
                                        FUN_23a334bc0(plVar14);
                                      }
                                      *plVar10 = *plVar10 + -1;
                                      if (*plVar10 == 0) {
                                        FUN_23a334bc0(plVar10);
                                      }
                                      *plVar1 = *plVar1 + -1;
                                      if (*plVar1 != 0) {
                                        return plVar14;
                                      }
                                      FUN_23a334bc0(plVar1);
                                      return plVar14;
                                    }
                                    uVar13 = *(undefined8 *)(param_1 + 0x60);
                                    uVar4 = *(undefined8 *)(param_1 + 0x68);
                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    uVar17 = 0xba;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plVar7 = DAT_23ed6a4f8;
                                  }
                                  goto joined_r0x00023e838073;
                                }
                              }
                              uVar13 = *(undefined8 *)(param_1 + 0x60);
                              uVar4 = *(undefined8 *)(param_1 + 0x68);
                              plVar8 = *(longlong **)(param_1 + 0x70);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              uVar17 = 0xba;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *plVar12 = *plVar12 + -1;
                              plVar7 = DAT_23ed6a4f8;
                              if (*plVar12 == 0) {
                                FUN_23a334bc0(plVar12);
                                uVar17 = 0xba;
                                plVar7 = DAT_23ed6a4f8;
                              }
                            }
                          }
                        }
                      }
                      goto joined_r0x00023e838073;
                    }
                  }
                  uVar13 = *(undefined8 *)(param_1 + 0x60);
                  uVar4 = *(undefined8 *)(param_1 + 0x68);
                  plVar8 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    FUN_23a334bc0(plVar12);
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    plVar10 = (longlong *)0x0;
                    FUN_23a334bc0(plVar11);
                    uVar17 = 0xb6;
                    plVar7 = DAT_23ed6a4f8;
                  }
                  else {
                    uVar17 = 0xb6;
                    plVar10 = (longlong *)0x0;
                    plVar7 = DAT_23ed6a4f8;
                  }
                }
              }
            }
            goto joined_r0x00023e838073;
          }
        }
        uVar13 = *(undefined8 *)(param_1 + 0x60);
        uVar4 = *(undefined8 *)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          FUN_23a334bc0(plVar12);
        }
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          plVar10 = (longlong *)0x0;
          FUN_23a334bc0(plVar11);
          uVar17 = 0xb5;
          plVar7 = DAT_23ed6a4f8;
        }
        else {
          uVar17 = 0xb5;
          plVar10 = (longlong *)0x0;
          plVar7 = DAT_23ed6a4f8;
        }
      }
    }
  }
  else {
    plVar11 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
    *plVar7 = *plVar7 + 1;
    uVar13 = _DAT_23eedc0b0;
    plVar11[3] = (longlong)plVar7;
    plVar7 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
    if (plVar7 != (longlong *)0x0) {
      lVar9 = FUN_23e94f9d0(param_1,plVar7);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        FUN_23a334bc0(plVar7);
      }
      if (lVar9 != 0) {
        plVar11[4] = lVar9;
        plVar7 = _DAT_23eedc130;
        *_DAT_23eedc130 = *_DAT_23eedc130 + 1;
        plVar11[5] = (longlong)plVar7;
        plVar8 = (longlong *)(*pcStack_80)(DAT_23ed6cd28,plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          FUN_23a334bc0();
        }
        if (plVar8 == (longlong *)0x0) {
          uVar13 = *(undefined8 *)(param_1 + 0x60);
          uVar4 = *(undefined8 *)(param_1 + 0x68);
          plVar8 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar17 = 0xb2;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar12 = *plVar12 + -1;
          plVar10 = (longlong *)0x0;
          plVar7 = DAT_23ed6a4f8;
          if (*plVar12 == 0) {
            FUN_23a334bc0(plVar12);
            uVar17 = 0xb2;
            plVar7 = DAT_23ed6a4f8;
          }
          goto joined_r0x00023e838073;
        }
        goto LAB_23e837a48;
      }
    }
    uVar13 = *(undefined8 *)(param_1 + 0x60);
    uVar4 = *(undefined8 *)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      FUN_23a334bc0(plVar12);
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      plVar10 = (longlong *)0x0;
      FUN_23a334bc0(plVar11);
      uVar17 = 0xb2;
      plVar7 = DAT_23ed6a4f8;
    }
    else {
      uVar17 = 0xb2;
      plVar10 = (longlong *)0x0;
      plVar7 = DAT_23ed6a4f8;
    }
  }
  goto joined_r0x00023e838073;
}
