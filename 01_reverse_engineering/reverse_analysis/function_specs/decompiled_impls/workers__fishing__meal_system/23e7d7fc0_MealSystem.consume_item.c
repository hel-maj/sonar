/* ===== 23e7d7fc0 workers.fishing.meal_system:321 ===== */
/* ghidra_name=FUN_23e7d7fc0 entry=23e7d7fc0 size=4437 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7d7fc0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong *plVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  code *pcVar9;
  longlong *plVar10;
  code *pcVar11;
  undefined8 uVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong *plVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  code *unaff_RBX;
  code *pcVar18;
  undefined8 uVar19;
  undefined1 auStack_98 [16];
  longlong *plStack_88;
  code *pcStack_78;
  longlong *plStack_70;
  undefined8 uStack_68;
  
  plVar7 = _DAT_23eedec48;
  param_3 = (longlong *)*param_3;
  plStack_88 = (longlong *)0x0;
  auStack_98 = (undefined1  [16])0x0;
  if (_DAT_23eedec48 == (longlong *)0x0) {
LAB_23e7d801e:
    _DAT_23eedec48 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedec40,DAT_23eed7940,0x30);
  }
  else {
    lVar13 = *_DAT_23eedec48;
    if (1 < lVar13) {
      *_DAT_23eedec48 = lVar13 + -1;
      goto LAB_23e7d801e;
    }
    if (_DAT_23eedec48[2] != 0) {
      *_DAT_23eedec48 = lVar13 + -1;
      if (lVar13 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e7d801e;
    }
  }
  plVar3 = _DAT_23eedec48;
  lVar13 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eedec48 + 9;
  lVar1 = *(longlong *)(lVar13 + 8);
  _DAT_23eedec48[0xf] = lVar1;
  *(longlong **)(lVar13 + 8) = plVar7;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed6cf28);
  if ((plVar7 == (longlong *)0x0) || (lVar13 = *plVar7, lVar13 == 0)) goto LAB_23e7d8a58;
  *(undefined4 *)(plVar3 + 5) = 0x143;
  plVar7 = (longlong *)FUN_23e94bb80(param_1,lVar13,uRam000000023eed74d8);
  if (plVar7 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    pcVar11 = (code *)0x0;
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar9 = (code *)0x0;
    plVar7 = (longlong *)0x0;
    uVar16 = 0x143;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    unaff_RBX = (code *)0x0;
    goto LAB_23e7d881d;
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7 = (longlong *)FUN_23e8bc2f0(param_3,DAT_23eed72a8);
  if (plVar7 == (longlong *)0x0) {
    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_88 = *(longlong **)(param_1 + 0x70);
    pcVar11 = (code *)0x0;
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar9 = (code *)0x0;
    unaff_RBX = (code *)0x0;
    uVar17 = 0x144;
    uVar16 = 0x144;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar7 = (longlong *)0x0;
    if (plStack_88 == (longlong *)0x0) {
      plVar7 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      goto LAB_23e7d8ad0;
    }
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 0x144;
    unaff_RBX = (code *)FUN_23e91bfe0(param_1,plVar7,DAT_23eed72a8);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    plVar7 = plRam000000023eed74f0;
    if (unaff_RBX == (code *)0x0) {
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      pcVar11 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar9 = (code *)0x0;
      plVar7 = (longlong *)0x0;
      uVar16 = 0x144;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    }
    else if (unaff_RBX == _Py_NoneStruct_exref) {
      uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar3 + 5) = 0x146;
      plVar7 = (longlong *)FUN_23e94bb80(param_1,uVar12,DAT_23eed74e0);
      if (plVar7 != (longlong *)0x0) {
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        pcVar18 = _Py_FalseStruct_exref;
        pcVar11 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        pcVar9 = (code *)0x0;
        plVar7 = (longlong *)0x0;
        *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23e7d862f:
        lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar3 = *(longlong **)(lVar13 + 0x28);
        plVar8 = (longlong *)plVar3[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
        *(undefined4 *)(plVar3 + 8) = 0xffffffff;
        if (plVar8 != (longlong *)0x0) {
          plVar3[2] = 0;
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))();
          }
        }
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))(plVar3);
        }
        plVar3[0xf] = 0;
        *(longlong *)unaff_RBX = *(longlong *)unaff_RBX + -1;
        if (*(longlong *)unaff_RBX == 0) {
          (**(code **)(*(longlong *)(unaff_RBX + 8) + 0x30))(unaff_RBX);
        }
        if (plVar7 != (longlong *)0x0) {
LAB_23e7d8695:
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
LAB_23e7d869b:
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
        }
        if (pcVar9 == (code *)0x0) goto LAB_23e7d86ba;
LAB_23e7d86aa:
        *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
        if (*(longlong *)pcVar9 == 0) {
          (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
        }
LAB_23e7d86ba:
        if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if ((pcVar11 != (code *)0x0) &&
           (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
          (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
        }
        lVar13 = *param_3;
        *param_3 = lVar13 + -1;
        if (lVar13 + -1 != 0) {
          return pcVar18;
        }
        (**(code **)(param_3[1] + 0x30))(param_3);
        return pcVar18;
      }
      auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_88 = *(longlong **)(param_1 + 0x70);
      pcVar11 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar9 = (code *)0x0;
      uVar16 = 0x146;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar7 = (longlong *)0x0;
    }
    else {
      *(undefined4 *)(plVar3 + 5) = 0x149;
      plStack_70 = plVar7;
      pcStack_78 = unaff_RBX;
      plVar7 = (longlong *)FUN_23e954670(param_1,param_3,DAT_23eed74e8,&pcStack_78);
      if (plVar7 == (longlong *)0x0) {
LAB_23e7d8a70:
        uVar12 = *(undefined8 *)(param_1 + 0x60);
        uVar19 = *(undefined8 *)(param_1 + 0x68);
        plVar14 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        plVar8 = (longlong *)FUN_23a388310(plVar7);
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        if (plVar8 == (longlong *)0x0) goto LAB_23e7d8a70;
        plVar7 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
        if ((plVar7 == (longlong *)0x0) &&
           (plVar7 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,0,4), plVar7 == (longlong *)0x0))
        {
          pcVar11 = (code *)0x0;
          plVar10 = (longlong *)0x0;
          pcVar9 = (code *)0x0;
        }
        else {
          pcVar9 = (code *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
          if ((pcVar9 == (code *)0x0) &&
             (pcVar9 = (code *)FUN_23a3c1b70(param_1,auStack_98,1,4), pcVar9 == (code *)0x0)) {
            pcVar11 = (code *)0x0;
            plVar10 = (longlong *)0x0;
          }
          else {
            plVar10 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
            if ((plVar10 == (longlong *)0x0) &&
               (plVar10 = (longlong *)FUN_23a3c1b70(param_1,auStack_98,2,4),
               plVar10 == (longlong *)0x0)) {
              pcVar11 = (code *)0x0;
            }
            else {
              pcVar11 = (code *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
              if (((pcVar11 != (code *)0x0) ||
                  (pcVar11 = (code *)FUN_23a3c1b70(param_1,auStack_98,3,4), pcVar11 != (code *)0x0))
                 && (cVar5 = FUN_23a3884a0(param_1,auStack_98,plVar8,4), cVar5 != '\0')) {
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                if (*plVar7 == 0) {
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                if (*(longlong *)pcVar9 == 0) {
                  (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
                }
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                if (*(longlong *)pcVar11 == 0) {
                  (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
                }
                iVar6 = FUN_23a35f020(plVar7);
                if (iVar6 == -1) {
                  auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                  plStack_88 = *(longlong **)(param_1 + 0x70);
                  uVar16 = 0x14b;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e7d881d;
                }
                if (iVar6 == 0) {
                  uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                  plVar14 = plRam000000023eed7520;
                  lVar13 = *(longlong *)(param_1 + 0x10);
                  plVar8 = *(longlong **)(lVar13 + 0xe28);
                  if (plVar8 == (longlong *)0x0) {
                    plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                  }
                  else {
                    lVar1 = plVar8[3];
                    *(int *)(lVar13 + 0xec0) = *(int *)(lVar13 + 0xec0) + -1;
                    *(longlong *)(lVar13 + 0xe28) = lVar1;
                    *plVar8 = 1;
                  }
                  pcVar18 = _PyRuntime_exref;
                  *(undefined1 (*) [16])(plVar8 + 4) = (undefined1  [16])0x0;
                  plVar4 = DAT_23eed7500;
                  lVar13 = *(longlong *)
                            (*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
                  lVar1 = plVar8[-1];
                  puVar2 = *(undefined8 **)(lVar13 + 8);
                  *puVar2 = plVar8 + -2;
                  plVar8[-2] = lVar13;
                  plVar8[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
                  *(longlong **)(lVar13 + 8) = plVar8 + -2;
                  plVar15 = DAT_23ed6a4c0;
                  *plVar14 = *plVar14 + 1;
                  plVar8[3] = (longlong)plVar14;
                  if (plVar15 == (longlong *)0x0) {
                    plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar15 == (longlong *)0x0) goto LAB_23e7d8a58;
                    *plVar15 = *plVar15 + 1;
                    DAT_23ed6a4c0 = plVar15;
                  }
                  plStack_70 = plVar4;
                  pcStack_78 = pcVar11;
                  lVar13 = FUN_23e94ed00(param_1,plVar15,&pcStack_78);
                  if (lVar13 == 0) {
                    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_88 = *(longlong **)(param_1 + 0x70);
                    uVar16 = 0x151;
                    uVar17 = 0x151;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 != 0) goto LAB_23e7d881d;
LAB_23e7d8f82:
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                    uVar16 = uVar17;
                  }
                  else {
                    plVar8[4] = lVar13;
                    plVar14 = DAT_23eed74a0;
                    *DAT_23eed74a0 = *DAT_23eed74a0 + 1;
                    plVar8[5] = (longlong)plVar14;
                    plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar8);
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    if (plVar14 != (longlong *)0x0) {
                      *(undefined4 *)(plVar3 + 5) = 0x151;
                      plVar8 = (longlong *)FUN_23e914090(param_1,uVar12,plVar14);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      if (plVar8 != (longlong *)0x0) {
                        *plVar8 = *plVar8 + -1;
                        if (*plVar8 == 0) {
                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                        }
LAB_23e7d8d57:
                        lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                        plVar3 = *(longlong **)(lVar13 + 0x28);
                        plVar8 = (longlong *)plVar3[2];
                        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                             *(undefined8 *)(lVar13 + 0x30);
                        *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                        if (plVar8 != (longlong *)0x0) {
                          plVar3[2] = 0;
                          *plVar8 = *plVar8 + -1;
                          if (*plVar8 == 0) {
                            (**(code **)(plVar8[1] + 0x30))();
                          }
                        }
                        *plVar3 = *plVar3 + -1;
                        if (*plVar3 == 0) {
                          (**(code **)(plVar3[1] + 0x30))(plVar3);
                        }
                        pcVar18 = _Py_FalseStruct_exref;
                        plVar3[0xf] = 0;
                        *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                        *(longlong *)unaff_RBX = *(longlong *)unaff_RBX + -1;
                        if (*(longlong *)unaff_RBX == 0) {
                          (**(code **)(*(longlong *)(unaff_RBX + 8) + 0x30))(unaff_RBX);
                          goto LAB_23e7d8695;
                        }
                        *plVar7 = *plVar7 + -1;
                        if (*plVar7 == 0) goto LAB_23e7d869b;
                        goto LAB_23e7d86aa;
                      }
                    }
                    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_88 = *(longlong **)(param_1 + 0x70);
                    uVar16 = 0x151;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                }
                else {
                  uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                  plVar14 = plRam000000023eed74f8;
                  lVar13 = *(longlong *)(param_1 + 0x10);
                  plVar8 = *(longlong **)(lVar13 + 0xe28);
                  if (plVar8 == (longlong *)0x0) {
                    plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                  }
                  else {
                    lVar1 = plVar8[3];
                    *(int *)(lVar13 + 0xec0) = *(int *)(lVar13 + 0xec0) + -1;
                    *(longlong *)(lVar13 + 0xe28) = lVar1;
                    *plVar8 = 1;
                  }
                  pcVar18 = _PyRuntime_exref;
                  *(undefined1 (*) [16])(plVar8 + 4) = (undefined1  [16])0x0;
                  plVar4 = DAT_23eed7500;
                  lVar13 = *(longlong *)
                            (*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
                  lVar1 = plVar8[-1];
                  puVar2 = *(undefined8 **)(lVar13 + 8);
                  *puVar2 = plVar8 + -2;
                  plVar8[-2] = lVar13;
                  plVar8[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
                  *(longlong **)(lVar13 + 8) = plVar8 + -2;
                  plVar15 = DAT_23ed6a4c0;
                  *plVar14 = *plVar14 + 1;
                  plVar8[3] = (longlong)plVar14;
                  if (plVar15 == (longlong *)0x0) {
                    plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar15 == (longlong *)0x0) {
LAB_23e7d8a58:
                      PyErr_PrintEx(0);
                      Py_Exit(1);
                      goto LAB_23e7d8a70;
                    }
                    *plVar15 = *plVar15 + 1;
                    DAT_23ed6a4c0 = plVar15;
                  }
                  plStack_70 = plVar4;
                  pcStack_78 = pcVar11;
                  lVar13 = FUN_23e94ed00(param_1,plVar15,&pcStack_78);
                  if (lVar13 == 0) {
                    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_88 = *(longlong **)(param_1 + 0x70);
                    uVar17 = 0x14c;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar8 = *plVar8 + -1;
                    uVar16 = 0x14c;
                    if (*plVar8 == 0) goto LAB_23e7d8f82;
                  }
                  else {
                    plVar8[4] = lVar13;
                    plVar14 = DAT_23eed74a0;
                    *DAT_23eed74a0 = *DAT_23eed74a0 + 1;
                    plVar8[5] = (longlong)plVar14;
                    plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar8);
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    if (plVar14 != (longlong *)0x0) {
                      *(undefined4 *)(plVar3 + 5) = 0x14c;
                      plVar8 = (longlong *)FUN_23e914090(param_1,uVar12);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      if (plVar8 != (longlong *)0x0) {
                        *plVar8 = *plVar8 + -1;
                        if (*plVar8 == 0) {
                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                        }
                        uStack_68 = uRam000000023eed7510;
                        *(undefined4 *)(plVar3 + 5) = 0x14d;
                        pcStack_78 = pcVar9;
                        plStack_70 = plVar10;
                        plVar8 = (longlong *)
                                 FUN_23e9578c0(param_1,param_3,DAT_23eed7508,&pcStack_78);
                        if (plVar8 == (longlong *)0x0) {
                          auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                          plStack_88 = *(longlong **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          uVar16 = 0x14d;
                        }
                        else {
                          iVar6 = FUN_23a35f020(plVar8);
                          lVar13 = *plVar8 + -1;
                          if (iVar6 == -1) {
                            auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_88 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar8 = lVar13;
                            uVar16 = 0x14d;
                            if (lVar13 == 0) {
                              (**(code **)(plVar8[1] + 0x30))(plVar8);
                              uVar16 = 0x14d;
                            }
                          }
                          else {
                            *plVar8 = lVar13;
                            if (lVar13 == 0) {
                              (**(code **)(plVar8[1] + 0x30))(plVar8);
                            }
                            if (iVar6 == 0) goto LAB_23e7d8d57;
                            uVar12 = FUN_23a3a0d40(DAT_23ed6cf28);
                            *(undefined4 *)(plVar3 + 5) = 0x14e;
                            plVar8 = (longlong *)FUN_23e94bb80(param_1,uVar12,uRam000000023eed7518);
                            if (plVar8 != (longlong *)0x0) {
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                (**(code **)(plVar8[1] + 0x30))(plVar8);
                              }
                              pcVar18 = _Py_TrueStruct_exref;
                              *(longlong *)_Py_TrueStruct_exref =
                                   *(longlong *)_Py_TrueStruct_exref + 1;
                              goto LAB_23e7d862f;
                            }
                            auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                            plStack_88 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            uVar16 = 0x14e;
                          }
                        }
                        goto LAB_23e7d881d;
                      }
                    }
                    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_88 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar16 = 0x14c;
                  }
                }
                goto LAB_23e7d881d;
              }
            }
          }
        }
        plVar14 = plStack_88;
        uVar12 = auStack_98._0_8_;
        uVar19 = auStack_98._8_8_;
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        plStack_88 = (longlong *)0x0;
        auStack_98 = (undefined1  [16])0x0;
        if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        if ((pcVar9 != (code *)0x0) &&
           (*(longlong *)pcVar9 = *(longlong *)pcVar9 + -1, *(longlong *)pcVar9 == 0)) {
          (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
        }
        if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if ((pcVar11 != (code *)0x0) &&
           (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
          (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
        }
      }
      uVar16 = 0x149;
      pcVar11 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      auStack_98._8_8_ = uVar19;
      auStack_98._0_8_ = uVar12;
      pcVar9 = (code *)0x0;
      plVar7 = (longlong *)0x0;
      plStack_88 = plVar14;
    }
LAB_23e7d881d:
    uVar17 = uVar16;
    if (plStack_88 == (longlong *)0x0) {
LAB_23e7d8ad0:
      plVar8 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar14 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar8[2] = 0;
      plVar8[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      *(undefined4 *)((longlong)plVar8 + 0x24) = uVar17;
      pcVar18 = _PyRuntime_exref;
      *(undefined4 *)(plVar8 + 4) = 0xffffffff;
      lVar13 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
      lVar1 = plVar8[-1];
      puVar2 = *(undefined8 **)(lVar13 + 8);
      *puVar2 = plVar8 + -2;
      plVar8[-2] = lVar13;
      plVar8[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar13 + 8) = plVar8 + -2;
      goto LAB_23e7d88d7;
    }
  }
  plVar15 = plStack_88;
  plVar14 = DAT_23ed6a4f8;
  plVar8 = plStack_88;
  if ((longlong *)plStack_88[3] != plVar3) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar14 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar8 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar8;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar14[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar13 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)((longlong)plVar14 + 0x24) = uVar16;
    *(undefined4 *)(plVar14 + 4) = 0xffffffff;
    lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
    lVar1 = plVar14[-1];
    puVar2 = *(undefined8 **)(lVar13 + 8);
    *puVar2 = plVar14 + -2;
    plVar14[-2] = lVar13;
    plVar14[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
    lVar1 = *plVar15;
    *(longlong **)(lVar13 + 8) = plVar14 + -2;
    plVar14[2] = (longlong)plVar15;
    plVar8 = plVar14;
    if (lVar1 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
  }
LAB_23e7d88d7:
  plStack_88 = plVar8;
  FUN_23e8bba40(plVar3,"oooooo",param_3,unaff_RBX,plVar7,pcVar9,plVar10,pcVar11);
  if (_DAT_23eedec48 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedec48 = (longlong *)0x0;
  }
  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar13 + 0x28);
  plVar8 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar8 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar8 = plStack_88;
  uVar19 = auStack_98._8_8_;
  plVar3[0xf] = 0;
  plStack_88 = (longlong *)0x0;
  uVar12 = auStack_98._0_8_;
  auStack_98 = (undefined1  [16])0x0;
  if ((unaff_RBX != (code *)0x0) &&
     (*(longlong *)unaff_RBX = *(longlong *)unaff_RBX + -1, *(longlong *)unaff_RBX == 0)) {
    (**(code **)(*(longlong *)(unaff_RBX + 8) + 0x30))(unaff_RBX);
  }
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((pcVar9 != (code *)0x0) &&
     (*(longlong *)pcVar9 = *(longlong *)pcVar9 + -1, *(longlong *)pcVar9 == 0)) {
    (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((pcVar11 != (code *)0x0) &&
     (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
    (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
  }
  lVar13 = *param_3;
  *param_3 = lVar13 + -1;
  if (lVar13 + -1 == 0) {
    (**(code **)(param_3[1] + 0x30))(param_3);
  }
  FUN_23a33aa70(param_1,uVar12,uVar19,plVar8);
  return (code *)0x0;
}
