/* ===== 23e795020 workers.fishing.garbage_disposal:212 ===== */
/* ghidra_name=FUN_23e795020 entry=23e795020 size=9218 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e795020(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  undefined8 uVar4;
  code *pcVar5;
  char cVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  undefined8 uVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  code *pcVar18;
  longlong *plVar19;
  undefined4 uVar20;
  code *pcVar21;
  code *pcVar22;
  longlong *plStack_e0;
  longlong *plStack_d8;
  undefined1 *puStack_c0;
  longlong *plStack_98;
  undefined8 uStack_90;
  undefined1 auStack_88 [16];
  longlong *aplStack_78 [7];
  
  plVar8 = _DAT_23eedac40;
  pcVar21 = (code *)*param_3;
  aplStack_78[0] = (longlong *)0x0;
  auStack_88 = (undefined1  [16])0x0;
  if (_DAT_23eedac40 == (longlong *)0x0) {
LAB_23e795085:
    _DAT_23eedac40 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedac38,DAT_23eedacf8);
  }
  else {
    lVar12 = *_DAT_23eedac40;
    if (1 < lVar12) {
      *_DAT_23eedac40 = lVar12 + -1;
      goto LAB_23e795085;
    }
    if (_DAT_23eedac40[2] != 0) {
      *_DAT_23eedac40 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e795085;
    }
  }
  plVar3 = _DAT_23eedac40;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eedac40 + 9;
  lVar1 = *(longlong *)(lVar12 + 8);
  _DAT_23eedac40[0xf] = lVar1;
  *(longlong **)(lVar12 + 8) = plVar8;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar10 = _DAT_23eed82d8;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(pcVar21,uVar10);
  if (plVar8 == (longlong *)0x0) {
    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    aplStack_78[0] = *(longlong **)(param_1 + 0x70);
    pcVar22 = (code *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar15 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    uVar20 = 0xd6;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar8 = (longlong *)0x0;
    goto LAB_23e795d5d;
  }
  *(undefined4 *)(plVar3 + 5) = 0xd6;
  plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23ed6cee0);
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
    if (plVar9 != (longlong *)0x0) goto LAB_23e795159;
LAB_23e795483:
    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    aplStack_78[0] = *(longlong **)(param_1 + 0x70);
    pcVar22 = (code *)0x0;
    plStack_e0 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar15 = (longlong *)0x0;
    plVar8 = (longlong *)0x0;
    uVar20 = 0xd6;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (aplStack_78[0] == (longlong *)0x0) {
      aplStack_78[0] = (longlong *)0x0;
LAB_23e7954d0:
      plVar11 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar19 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar19;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar18 = _PyRuntime_exref;
      plVar11[2] = 0;
      plVar11[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar12 = *(longlong *)(pcVar18 + 0x1f8);
      *(undefined4 *)((longlong)plVar11 + 0x24) = uVar20;
      lVar12 = *(longlong *)(lVar12 + 0x10);
      *(undefined4 *)(plVar11 + 4) = 0xffffffff;
      lVar12 = *(longlong *)(lVar12 + 0x2e8);
      lVar1 = plVar11[-1];
      puVar2 = *(undefined8 **)(lVar12 + 8);
      *puVar2 = plVar11 + -2;
      plVar11[-2] = lVar12;
      plVar11[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar12 + 8) = plVar11 + -2;
      if ((aplStack_78[0] != (longlong *)0x0) &&
         (*aplStack_78[0] = *aplStack_78[0] + -1, *aplStack_78[0] == 0)) {
        (**(code **)(aplStack_78[0][1] + 0x30))(aplStack_78[0]);
      }
      goto LAB_23e795e23;
    }
  }
  else {
    if (plVar9 == (longlong *)0x0) goto LAB_23e795483;
LAB_23e795159:
    iVar7 = FUN_23a35f020(plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (iVar7 == -1) {
      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
      aplStack_78[0] = *(longlong **)(param_1 + 0x70);
      uVar20 = 0xd6;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e795d50:
      pcVar22 = (code *)0x0;
      plStack_e0 = (longlong *)0x0;
      plVar15 = (longlong *)0x0;
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
    }
    else {
      pcVar18 = pcVar21;
      if (iVar7 == 0) {
        uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
        plVar9 = _DAT_23eed83c0;
        lVar12 = *(longlong *)(param_1 + 0x10);
        plVar8 = *(longlong **)(lVar12 + 0xe20);
        if (plVar8 == (longlong *)0x0) {
          plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar1 = plVar8[3];
          *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
          *(longlong *)(lVar12 + 0xe20) = lVar1;
          *plVar8 = 1;
        }
        pcVar22 = _PyRuntime_exref;
        plVar8[4] = 0;
        lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar22 + 0x1f8) + 0x10) + 0x2e8);
        lVar1 = plVar8[-1];
        puVar2 = *(undefined8 **)(lVar12 + 8);
        *puVar2 = plVar8 + -2;
        plVar8[-2] = lVar12;
        plVar8[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
        *(longlong **)(lVar12 + 8) = plVar8 + -2;
        uVar4 = _DAT_23eed82d8;
        *plVar9 = *plVar9 + 1;
        plVar8[3] = (longlong)plVar9;
        plVar11 = (longlong *)FUN_23e8bc2f0(pcVar21,uVar4);
        uVar4 = DAT_23ed6cd28;
        if (plVar11 != (longlong *)0x0) {
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar9 == (longlong *)0x0) goto LAB_23e7968c8;
            *plVar9 = *plVar9 + 1;
            DAT_23ed6a4c0 = plVar9;
          }
          uStack_90 = uVar4;
          plStack_98 = plVar11;
          lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
          if (lVar12 != 0) {
            plVar8[4] = lVar12;
            plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar8);
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            if (plVar9 == (longlong *)0x0) {
              auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
              aplStack_78[0] = *(longlong **)(param_1 + 0x70);
              pcVar22 = (code *)0x0;
              plStack_e0 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar15 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              uVar20 = 0xd7;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar8 = (longlong *)0x0;
            }
            else {
              *(undefined4 *)(plVar3 + 5) = 0xd7;
              plVar8 = (longlong *)FUN_23e914090(param_1,uVar10,plVar9);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plVar8 != (longlong *)0x0) {
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                pcVar18 = _Py_FalseStruct_exref;
                pcVar22 = (code *)0x0;
                plVar15 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plStack_e0 = (longlong *)0x0;
                plVar8 = (longlong *)0x0;
                *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23e795322:
                lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                plVar3 = *(longlong **)(lVar12 + 0x28);
                plVar11 = (longlong *)plVar3[2];
                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
                *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                if (plVar11 != (longlong *)0x0) {
                  plVar3[2] = 0;
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))();
                  }
                }
                *plVar3 = *plVar3 + -1;
                if (*plVar3 == 0) {
                  (**(code **)(plVar3[1] + 0x30))(plVar3);
                }
                plVar3[0xf] = 0;
                goto LAB_23e79539b;
              }
              auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
              aplStack_78[0] = *(longlong **)(param_1 + 0x70);
              pcVar22 = (code *)0x0;
              plStack_e0 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar15 = (longlong *)0x0;
              plVar8 = (longlong *)0x0;
              uVar20 = 0xd7;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar9 = (longlong *)0x0;
            }
            goto LAB_23e795d5d;
          }
        }
        auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
        aplStack_78[0] = *(longlong **)(param_1 + 0x70);
        uVar20 = 0xd7;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
          uVar20 = 0xd7;
        }
        goto LAB_23e795d50;
      }
      uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar9 = _DAT_23eed83c8;
      lVar12 = *(longlong *)(param_1 + 0x10);
      plVar8 = *(longlong **)(lVar12 + 0xe20);
      if (plVar8 == (longlong *)0x0) {
        plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar1 = plVar8[3];
        *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
        *(longlong *)(lVar12 + 0xe20) = lVar1;
        *plVar8 = 1;
      }
      pcVar22 = _PyRuntime_exref;
      plVar8[4] = 0;
      lVar12 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar22 + 0x1f8) + 0x10) + 0x2e8);
      lVar1 = plVar8[-1];
      puVar2 = *(undefined8 **)(lVar12 + 8);
      *puVar2 = plVar8 + -2;
      plVar8[-2] = lVar12;
      plVar8[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar12 + 8) = plVar8 + -2;
      uVar4 = _DAT_23eed82d8;
      *plVar9 = *plVar9 + 1;
      plVar8[3] = (longlong)plVar9;
      plVar11 = (longlong *)FUN_23e8bc2f0(pcVar21,uVar4);
      uVar4 = DAT_23ed6cd28;
      if (plVar11 == (longlong *)0x0) {
LAB_23e795f80:
        auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
        aplStack_78[0] = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        uVar20 = 0xda;
        goto LAB_23e795d50;
      }
      if (DAT_23ed6a4c0 == (longlong *)0x0) {
        plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar9 != (longlong *)0x0) {
          *plVar9 = *plVar9 + 1;
          DAT_23ed6a4c0 = plVar9;
          goto LAB_23e795670;
        }
LAB_23e7968c8:
        PyErr_PrintEx(0,0);
        Py_Exit(1);
        plVar8 = plVar11;
        pcVar21 = pcVar18;
LAB_23e7968db:
        auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
        aplStack_78[0] = *(longlong **)(param_1 + 0x70);
        pcVar22 = (code *)0x0;
        plStack_e0 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar15 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        uVar20 = 0xeb;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
LAB_23e795670:
        uStack_90 = uVar4;
        plStack_98 = plVar11;
        lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        if (lVar12 == 0) goto LAB_23e795f80;
        plVar8[4] = lVar12;
        plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar8);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar9 == (longlong *)0x0) {
          auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
          aplStack_78[0] = *(longlong **)(param_1 + 0x70);
          pcVar22 = (code *)0x0;
          plStack_e0 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar15 = (longlong *)0x0;
          plVar9 = (longlong *)0x0;
          uVar20 = 0xda;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar8 = (longlong *)0x0;
        }
        else {
          *(undefined4 *)(plVar3 + 5) = 0xda;
          plVar8 = (longlong *)FUN_23e914090(param_1,uVar10);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (plVar8 == (longlong *)0x0) {
            auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
            aplStack_78[0] = *(longlong **)(param_1 + 0x70);
            pcVar22 = (code *)0x0;
            plStack_e0 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar15 = (longlong *)0x0;
            plVar8 = (longlong *)0x0;
            uVar20 = 0xda;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar9 = (longlong *)0x0;
          }
          else {
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            plVar8 = (longlong *)FUN_23e8bc2f0(pcVar21,_DAT_23eed82b0);
            if (plVar8 == (longlong *)0x0) {
              auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
              aplStack_78[0] = *(longlong **)(param_1 + 0x70);
              pcVar22 = (code *)0x0;
              plStack_e0 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar15 = (longlong *)0x0;
              plVar9 = (longlong *)0x0;
              uVar20 = 0xdd;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar8 = (longlong *)0x0;
            }
            else {
              iVar7 = FUN_23e913250(plVar8,_DAT_23eed8350);
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              if (iVar7 == -1) {
                auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                uVar20 = 0xdd;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e795d50;
              }
              if (iVar7 == 1) {
                plVar8 = (longlong *)FUN_23e8d7870(param_1,_DAT_23eed83d0);
              }
              else {
                plVar8 = (longlong *)FUN_23e8d7870(param_1,_DAT_23eed83d8);
              }
              plVar9 = (longlong *)FUN_23e94b990(plVar8);
              plVar19 = (longlong *)FUN_23ebf7180(plVar9);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (plVar19 == (longlong *)0x0) goto LAB_23e7968db;
              if (pcVar21 == (code *)0x0) {
                lVar12 = plVar19[1];
                if (*(code **)(lVar12 + 0xe0) == (code *)0x0) {
                  plStack_d8 = (longlong *)0x0;
                  pcVar22 = (code *)0x0;
                  plVar11 = (longlong *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  plVar16 = (longlong *)0x0;
LAB_23e7964c3:
                  PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,
                               "\'%s\' object is not an iterator",*(undefined8 *)(lVar12 + 0x18));
                  plVar15 = plVar11;
                  plVar9 = plVar16;
                }
                else {
                  plStack_d8 = (longlong *)(**(code **)(lVar12 + 0xe0))();
                  if (plStack_d8 != (longlong *)0x0) {
                    plVar14 = (longlong *)FUN_23a388310(plStack_d8);
                    if (plVar14 == (longlong *)0x0) {
                      pcVar22 = (code *)0x0;
                      plVar11 = (longlong *)0x0;
                      plVar16 = (longlong *)0x0;
                      plStack_e0 = (longlong *)0x0;
LAB_23e796c33:
                      pcVar18 = *(code **)(param_1 + 0x60);
                      uVar10 = *(undefined8 *)(param_1 + 0x68);
                      plVar13 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar9 = plVar16;
                    }
                    else {
                      plVar9 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
                      if ((plVar9 == (longlong *)0x0) &&
                         (plVar9 = (longlong *)FUN_23a3c1b70(param_1,auStack_88,0),
                         plVar9 == (longlong *)0x0)) {
                        pcVar22 = (code *)0x0;
                        plVar11 = (longlong *)0x0;
                        plVar16 = (longlong *)0x0;
                        plStack_e0 = (longlong *)0x0;
                        plVar15 = (longlong *)0x0;
                      }
                      else {
                        puStack_c0 = auStack_88;
                        plVar15 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
                        if ((plVar15 != (longlong *)0x0) ||
                           (plVar15 = (longlong *)FUN_23a3c1b70(param_1,puStack_c0,1),
                           plVar15 != (longlong *)0x0)) {
                          cVar6 = FUN_23a3884a0(param_1,puStack_c0,plVar14);
                          lVar12 = *plVar14;
                          if (cVar6 != '\0') {
                            *plVar14 = lVar12 + -1;
                            if (lVar12 + -1 == 0) {
                              (**(code **)(plVar14[1] + 0x30))(plVar14);
                            }
                            if (*plVar9 == 0) {
                              (**(code **)(plVar9[1] + 0x30))(plVar9);
                            }
                            if (*plVar15 == 0) {
                              (**(code **)(plVar15[1] + 0x30))(plVar15);
                            }
                            auStack_88._8_8_ =
                                 PyUnicode_FromFormat
                                           ("cannot access local variable \'%U\' where it is not associated with a value"
                                            ,DAT_23eed80d0);
                            auStack_88._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
                            *(longlong *)auStack_88._0_8_ = *(longlong *)auStack_88._0_8_ + 1;
                            aplStack_78[0] = (longlong *)0x0;
                            if ((code *)auStack_88._0_8_ != _Py_NoneStruct_exref) {
                              FUN_23e91b1b0(param_1,puStack_c0,auStack_88 + 8,aplStack_78);
                            }
                            pcVar22 = (code *)0x0;
                            plStack_e0 = (longlong *)0x0;
                            FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_88._8_8_);
                            uVar20 = 0xec;
                            plVar13 = aplStack_78[0];
                            pcVar18 = (code *)auStack_88._0_8_;
                            uVar10 = auStack_88._8_8_;
                            goto LAB_23e796040;
                          }
                        }
                        pcVar22 = (code *)0x0;
                        plVar11 = (longlong *)0x0;
                        plVar16 = (longlong *)0x0;
                        plStack_e0 = (longlong *)0x0;
                      }
LAB_23e796663:
                      plVar13 = aplStack_78[0];
                      pcVar18 = (code *)auStack_88._0_8_;
                      uVar10 = auStack_88._8_8_;
                      aplStack_78[0] = (longlong *)0x0;
                      auStack_88 = (undefined1  [16])0x0;
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                      }
                      aplStack_78[0] = (longlong *)0x0;
                      auStack_88 = (undefined1  [16])0x0;
                      if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      plVar9 = plVar16;
                      if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0))
                      {
                        (**(code **)(plVar15[1] + 0x30))(plVar15);
                      }
                    }
                    plVar15 = plVar11;
                    uVar20 = 0xeb;
                    goto LAB_23e796040;
                  }
                  plStack_d8 = (longlong *)0x0;
                  pcVar22 = (code *)0x0;
                  plStack_e0 = (longlong *)0x0;
                  plVar15 = (longlong *)0x0;
                  plVar9 = (longlong *)0x0;
                }
LAB_23e7964fc:
                cVar6 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                if (cVar6 != '\0') {
                  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar3 = *(longlong **)(lVar12 + 0x28);
                  plVar11 = (longlong *)plVar3[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                       *(undefined8 *)(lVar12 + 0x30);
                  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                  if (plVar11 != (longlong *)0x0) {
                    plVar3[2] = 0;
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))();
                    }
                  }
                  *plVar3 = *plVar3 + -1;
                  if (*plVar3 == 0) {
                    (**(code **)(plVar3[1] + 0x30))(plVar3);
                  }
                  plVar3[0xf] = 0;
                  if ((plStack_d8 != (longlong *)0x0) &&
                     (*plStack_d8 = *plStack_d8 + -1, *plStack_d8 == 0)) {
                    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
                  }
                  lVar12 = *plVar19;
                  *plVar19 = lVar12 + -1;
                  if (lVar12 + -1 == 0) {
                    (**(code **)(plVar19[1] + 0x30))(plVar19);
                  }
                  pcVar18 = _Py_TrueStruct_exref;
                  *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
LAB_23e79539b:
                  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
                    (**(code **)(plVar8[1] + 0x30))(plVar8);
                  }
                  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  if ((plStack_e0 != (longlong *)0x0) &&
                     (lVar12 = *plStack_e0, *plStack_e0 = lVar12 + -1, lVar12 + -1 == 0)) {
                    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
                  }
                  if ((pcVar22 != (code *)0x0) &&
                     (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0))
                  {
                    (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
                  }
                  *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
                  if (*(longlong *)pcVar21 != 0) {
                    return pcVar18;
                  }
                  (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
                  return pcVar18;
                }
                plVar13 = *(longlong **)(param_1 + 0x70);
                pcVar18 = *(code **)(param_1 + 0x60);
                uVar10 = *(undefined8 *)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                aplStack_78[0] = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                auStack_88 = (undefined1  [16])0x0;
                if (plStack_d8 != (longlong *)0x0) {
                  uVar20 = 0xeb;
                  goto LAB_23e796040;
                }
                uVar20 = 0xeb;
              }
              else {
                plStack_e0 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                plStack_d8 = (longlong *)0x0;
                plVar16 = (longlong *)0x0;
                pcVar22 = (code *)0x0;
                do {
                  lVar12 = plVar19[1];
                  if (*(code **)(lVar12 + 0xe0) == (code *)0x0) goto LAB_23e7964c3;
                  plVar13 = (longlong *)(**(code **)(lVar12 + 0xe0))();
                  plVar15 = plVar11;
                  plVar9 = plVar16;
                  if (plVar13 == (longlong *)0x0) goto LAB_23e7964fc;
                  if ((plStack_d8 != (longlong *)0x0) &&
                     (*plStack_d8 = *plStack_d8 + -1, *plStack_d8 == 0)) {
                    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
                  }
                  plVar14 = (longlong *)FUN_23a388310(plVar13);
                  plStack_d8 = plVar13;
                  if (plVar14 == (longlong *)0x0) goto LAB_23e796c33;
                  plVar9 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
                  if ((plVar9 == (longlong *)0x0) &&
                     (plVar9 = (longlong *)FUN_23a3c1b70(param_1,auStack_88,0,2),
                     plVar9 == (longlong *)0x0)) {
                    plVar15 = (longlong *)0x0;
                    goto LAB_23e796663;
                  }
                  puStack_c0 = auStack_88;
                  plVar15 = (longlong *)(**(code **)(plVar14[1] + 0xe0))(plVar14);
                  if ((plVar15 == (longlong *)0x0) &&
                     (plVar15 = (longlong *)FUN_23a3c1b70(param_1,puStack_c0,1,2),
                     plVar15 == (longlong *)0x0)) goto LAB_23e796663;
                  cVar6 = FUN_23a3884a0(param_1,puStack_c0,plVar14,2);
                  lVar12 = *plVar14;
                  if (cVar6 == '\0') goto LAB_23e796663;
                  *plVar14 = lVar12 + -1;
                  if (lVar12 + -1 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  lVar12 = *plVar9;
                  *plVar9 = lVar12 + 1;
                  if (plVar16 != (longlong *)0x0) {
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                      lVar12 = *plVar9 + -1;
                    }
                    else {
                      lVar12 = *plVar9 + -1;
                    }
                  }
                  *plVar9 = lVar12;
                  if (lVar12 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  lVar12 = *plVar15;
                  *plVar15 = lVar12 + 1;
                  if (plVar11 != (longlong *)0x0) {
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                      lVar12 = *plVar15 + -1;
                    }
                    else {
                      lVar12 = *plVar15 + -1;
                    }
                  }
                  *plVar15 = lVar12;
                  if (lVar12 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  plVar11 = (longlong *)FUN_23e8bc2f0(pcVar21,_DAT_23eed82d8);
                  if (plVar11 == (longlong *)0x0) {
LAB_23e79691a:
                    plVar13 = *(longlong **)(param_1 + 0x70);
                    pcVar18 = *(code **)(param_1 + 0x60);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar20 = 0xec;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar10 = *(undefined8 *)(param_1 + 0x68);
                    goto LAB_23e796040;
                  }
                  plVar16 = (longlong *)FUN_23e8c6f80(plVar11,plVar15);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar16 == (longlong *)0x0) goto LAB_23e79691a;
                  if ((plStack_e0 != (longlong *)0x0) &&
                     (lVar12 = *plStack_e0, *plStack_e0 = lVar12 + -1, lVar12 + -1 == 0)) {
                    (**(code **)(plStack_e0[1] + 0x30))();
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xed;
                  plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar16,DAT_23ed6cee0);
                  plStack_e0 = plVar16;
                  if (plVar11 == (longlong *)0x0) {
LAB_23e796964:
                    pcVar18 = *(code **)(param_1 + 0x60);
                    plVar13 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar20 = 0xed;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar10 = *(undefined8 *)(param_1 + 0x68);
                    goto LAB_23e796040;
                  }
                  iVar7 = FUN_23a35f020(plVar11);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (iVar7 == -1) goto LAB_23e796964;
                  plVar11 = plVar8;
                  if (iVar7 == 0) {
                    uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
                    plVar14 = _DAT_23eed83e0;
                    lVar12 = *(longlong *)(param_1 + 0x10);
                    plVar16 = *(longlong **)(lVar12 + 0xe28);
                    if (plVar16 == (longlong *)0x0) {
                      plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                    }
                    else {
                      lVar1 = plVar16[3];
                      *(int *)(lVar12 + 0xec0) = *(int *)(lVar12 + 0xec0) + -1;
                      *(longlong *)(lVar12 + 0xe28) = lVar1;
                      *plVar16 = 1;
                    }
                    pcVar18 = _PyRuntime_exref;
                    *(undefined1 (*) [16])(plVar16 + 4) = (undefined1  [16])0x0;
                    lVar12 = *(longlong *)
                              (*(longlong *)(*(longlong *)(pcVar18 + 0x1f8) + 0x10) + 0x2e8);
                    lVar1 = plVar16[-1];
                    puVar2 = *(undefined8 **)(lVar12 + 8);
                    *puVar2 = plVar16 + -2;
                    plVar16[-2] = lVar12;
                    plVar16[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
                    *(longlong **)(lVar12 + 8) = plVar16 + -2;
                    *plVar14 = *plVar14 + 1;
                    plVar16[3] = (longlong)plVar14;
                    uVar4 = DAT_23ed6cd28;
                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                      plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                      pcVar18 = pcVar21;
                      if (plVar14 == (longlong *)0x0) goto LAB_23e7968c8;
                      *plVar14 = *plVar14 + 1;
                      DAT_23ed6a4c0 = plVar14;
                    }
                    uStack_90 = uVar4;
                    plStack_98 = plVar15;
                    lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
                    if (lVar12 == 0) {
                      auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        FUN_23a334bc0(plVar16);
                        uVar20 = 0xee;
                        plVar13 = aplStack_78[0];
                        pcVar18 = (code *)auStack_88._0_8_;
                        uVar10 = auStack_88._8_8_;
                      }
                      else {
                        uVar20 = 0xee;
                        plVar13 = aplStack_78[0];
                        pcVar18 = (code *)auStack_88._0_8_;
                        uVar10 = auStack_88._8_8_;
                      }
                      goto LAB_23e796040;
                    }
                    plVar16[4] = lVar12;
                    plVar11 = _DAT_23eed83e8;
                    *_DAT_23eed83e8 = *_DAT_23eed83e8 + 1;
                    plVar16[5] = (longlong)plVar11;
                    plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                    }
                    if (plVar11 != (longlong *)0x0) {
                      *(undefined4 *)(plVar3 + 5) = 0xee;
                      plVar16 = (longlong *)FUN_23e914090(param_1,uVar10);
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      if (plVar16 != (longlong *)0x0) {
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          (**(code **)(plVar16[1] + 0x30))(plVar16);
                        }
                        lVar12 = *(longlong *)_Py_FalseStruct_exref;
LAB_23e796e10:
                        pcVar18 = _Py_FalseStruct_exref;
                        *(longlong *)_Py_FalseStruct_exref = lVar12 + 1;
                        lVar12 = *plVar13;
                        *plVar13 = lVar12 + -1;
                        if (lVar12 + -1 == 0) {
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        lVar12 = *plVar19;
                        *plVar19 = lVar12 + -1;
                        if (lVar12 + -1 == 0) {
                          (**(code **)(plVar19[1] + 0x30))(plVar19);
                        }
                        goto LAB_23e795322;
                      }
                    }
                    plVar13 = *(longlong **)(param_1 + 0x70);
                    pcVar18 = *(code **)(param_1 + 0x60);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar20 = 0xee;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar10 = *(undefined8 *)(param_1 + 0x68);
                    goto LAB_23e796040;
                  }
                  lVar12 = FUN_23e8df960();
                  if (lVar12 == 0) {
                    FUN_23e915740(param_1,puStack_c0,DAT_23eed81e0);
                    uVar20 = 0xf1;
                    plVar13 = aplStack_78[0];
                    pcVar18 = (code *)auStack_88._0_8_;
                    uVar10 = auStack_88._8_8_;
                    goto LAB_23e796040;
                  }
                  plVar14 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eed83f0);
                  if (plVar14 == (longlong *)0x0) {
LAB_23e7969ac:
                    pcVar18 = *(code **)(param_1 + 0x60);
                    plVar13 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar20 = 0xf1;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar10 = *(undefined8 *)(param_1 + 0x68);
                    goto LAB_23e796040;
                  }
                  plVar17 = (longlong *)FUN_23e8bd350(plVar16);
                  if (plVar17 == (longlong *)0x0) {
                    auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14,aplStack_78[0],0);
                      uVar20 = 0xf1;
                      plVar13 = aplStack_78[0];
                      pcVar18 = (code *)auStack_88._0_8_;
                      uVar10 = auStack_88._8_8_;
                    }
                    else {
                      uVar20 = 0xf1;
                      plVar13 = aplStack_78[0];
                      pcVar18 = (code *)auStack_88._0_8_;
                      uVar10 = auStack_88._8_8_;
                    }
                    goto LAB_23e796040;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xf1;
                  pcVar18 = (code *)FUN_23e914090(param_1,plVar14);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  *plVar17 = *plVar17 + -1;
                  if (*plVar17 == 0) {
                    (**(code **)(plVar17[1] + 0x30))(plVar17);
                  }
                  if (pcVar18 == (code *)0x0) goto LAB_23e7969ac;
                  if ((pcVar22 != (code *)0x0) &&
                     (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0))
                  {
                    (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
                  }
                  if (pcVar18 == _Py_NoneStruct_exref) {
                    uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
                    plVar14 = _DAT_23eed83f8;
                    lVar12 = *(longlong *)(param_1 + 0x10);
                    plVar16 = *(longlong **)(lVar12 + 0xe20);
                    if (plVar16 == (longlong *)0x0) {
                      plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                    }
                    else {
                      lVar1 = plVar16[3];
                      *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
                      *(longlong *)(lVar12 + 0xe20) = lVar1;
                      *plVar16 = 1;
                    }
                    pcVar22 = _PyRuntime_exref;
                    plVar16[4] = 0;
                    lVar12 = *(longlong *)
                              (*(longlong *)(*(longlong *)(pcVar22 + 0x1f8) + 0x10) + 0x2e8);
                    lVar1 = plVar16[-1];
                    puVar2 = *(undefined8 **)(lVar12 + 8);
                    *puVar2 = plVar16 + -2;
                    plVar16[-2] = lVar12;
                    plVar16[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
                    *(longlong **)(lVar12 + 8) = plVar16 + -2;
                    *plVar14 = *plVar14 + 1;
                    plVar16[3] = (longlong)plVar14;
                    uVar4 = DAT_23ed6cd28;
                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                      plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                      pcVar18 = pcVar21;
                      if (plVar14 == (longlong *)0x0) goto LAB_23e7968c8;
                      *plVar14 = *plVar14 + 1;
                      DAT_23ed6a4c0 = plVar14;
                    }
                    uStack_90 = uVar4;
                    plStack_98 = plVar15;
                    lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
                    if (lVar12 == 0) {
                      auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        FUN_23a334bc0(plVar16);
                        uVar20 = 0xf3;
                        plVar13 = aplStack_78[0];
                        pcVar22 = _Py_NoneStruct_exref;
                        pcVar18 = (code *)auStack_88._0_8_;
                        uVar10 = auStack_88._8_8_;
                      }
                      else {
                        uVar20 = 0xf3;
                        plVar13 = aplStack_78[0];
                        pcVar22 = _Py_NoneStruct_exref;
                        pcVar18 = (code *)auStack_88._0_8_;
                        uVar10 = auStack_88._8_8_;
                      }
                    }
                    else {
                      plVar16[4] = lVar12;
                      plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                      }
                      if (plVar11 != (longlong *)0x0) {
                        *(undefined4 *)(plVar3 + 5) = 0xf3;
                        plVar16 = (longlong *)FUN_23e914090(param_1,uVar10);
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          (**(code **)(plVar11[1] + 0x30))(plVar11);
                        }
                        if (plVar16 != (longlong *)0x0) {
                          *plVar16 = *plVar16 + -1;
                          if (*plVar16 == 0) {
                            FUN_23a334bc0(plVar16);
                          }
                          lVar12 = *(longlong *)_Py_FalseStruct_exref;
                          pcVar22 = _Py_NoneStruct_exref;
                          goto LAB_23e796e10;
                        }
                      }
                      pcVar18 = *(code **)(param_1 + 0x60);
                      plVar13 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pcVar22 = _Py_NoneStruct_exref;
                      uVar20 = 0xf3;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      uVar10 = *(undefined8 *)(param_1 + 0x68);
                    }
                    goto LAB_23e796040;
                  }
                  plVar11 = (longlong *)FUN_23e8bc2f0(pcVar21,DAT_23eed82c0);
                  pcVar22 = pcVar18;
                  if (plVar11 == (longlong *)0x0) {
LAB_23e7969f4:
                    pcVar18 = *(code **)(param_1 + 0x60);
                    plVar13 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar20 = 0xf6;
                    uVar10 = *(undefined8 *)(param_1 + 0x68);
                    goto LAB_23e796040;
                  }
                  cVar6 = FUN_23a39bc50(param_1,plVar11,plVar9,pcVar18);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (cVar6 == '\0') goto LAB_23e7969f4;
                  uVar10 = FUN_23a3a0d40(DAT_23ed6cf28);
                  plVar11 = _DAT_23eed8400;
                  lVar12 = *(longlong *)(param_1 + 0x10);
                  plVar14 = *(longlong **)(lVar12 + 0xe20);
                  if (plVar14 == (longlong *)0x0) {
                    plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                  }
                  else {
                    lVar1 = plVar14[3];
                    *(int *)(lVar12 + 0xebc) = *(int *)(lVar12 + 0xebc) + -1;
                    *(longlong *)(lVar12 + 0xe20) = lVar1;
                    *plVar14 = 1;
                  }
                  pcVar5 = _PyRuntime_exref;
                  plVar14[4] = 0;
                  lVar12 = *(longlong *)
                            (*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
                  lVar1 = plVar14[-1];
                  puVar2 = *(undefined8 **)(lVar12 + 8);
                  *puVar2 = plVar14 + -2;
                  plVar14[-2] = lVar12;
                  plVar14[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
                  *(longlong **)(lVar12 + 8) = plVar14 + -2;
                  *plVar11 = *plVar11 + 1;
                  plVar14[3] = (longlong)plVar11;
                  uVar4 = DAT_23ed6cd28;
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    plVar13 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    plVar11 = plVar16;
                    if (plVar13 == (longlong *)0x0) goto LAB_23e7968c8;
                    *plVar13 = *plVar13 + 1;
                    DAT_23ed6a4c0 = plVar13;
                  }
                  uStack_90 = uVar4;
                  plStack_98 = plVar15;
                  lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
                  if (lVar12 == 0) {
                    auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                      uVar20 = 0xf7;
                      plVar13 = aplStack_78[0];
                      pcVar18 = (code *)auStack_88._0_8_;
                      uVar10 = auStack_88._8_8_;
                    }
                    else {
                      uVar20 = 0xf7;
                      plVar13 = aplStack_78[0];
                      pcVar18 = (code *)auStack_88._0_8_;
                      uVar10 = auStack_88._8_8_;
                    }
                    goto LAB_23e796040;
                  }
                  plVar14[4] = lVar12;
                  plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar14);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (plVar11 == (longlong *)0x0) {
LAB_23e796a3f:
                    pcVar18 = *(code **)(param_1 + 0x60);
                    plVar13 = *(longlong **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar20 = 0xf7;
                    uVar10 = *(undefined8 *)(param_1 + 0x68);
                    goto LAB_23e796040;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xf7;
                  plVar16 = (longlong *)FUN_23e914090(param_1,uVar10);
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar16 == (longlong *)0x0) goto LAB_23e796a3f;
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                  }
                  lVar12 = *(longlong *)(param_1 + 0x10);
                  if ((((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160) != 0) ||
                       (*(int *)(lVar12 + 0x78) != 0)) && (iVar7 = Py_MakePendingCalls(), iVar7 < 0)
                      ) && (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e796000;
                  if (*(int *)(lVar12 + 0x68) == 0) {
                    plVar14 = *(longlong **)(param_1 + 0x90);
                  }
                  else {
                    PyEval_SaveThread();
                    PyEval_AcquireThread(param_1);
                    plVar14 = *(longlong **)(param_1 + 0x90);
                  }
                  plVar11 = plVar15;
                  plVar16 = plVar9;
                } while (plVar14 == (longlong *)0x0);
                plVar11 = *(longlong **)(param_1 + 0x60);
                plVar16 = *(longlong **)(param_1 + 0x68);
                plVar13 = *(longlong **)(param_1 + 0x70);
                *(longlong **)(param_1 + 0x60) = plVar14;
                *(undefined8 *)(param_1 + 0x90) = 0;
                *plVar14 = *plVar14 + 1;
                *(undefined8 *)(param_1 + 0x68) = 0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                  (**(code **)(plVar11[1] + 0x30))();
                }
                if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
LAB_23e796000:
                plVar13 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar18 = *(code **)(param_1 + 0x60);
                uVar20 = 0xeb;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar10 = *(undefined8 *)(param_1 + 0x68);
LAB_23e796040:
                aplStack_78[0] = (longlong *)0x0;
                auStack_88 = (undefined1  [16])0x0;
                lVar12 = *plStack_d8;
                *plStack_d8 = lVar12 + -1;
                if (lVar12 + -1 == 0) {
                  (**(code **)(plStack_d8[1] + 0x30))();
                }
              }
              lVar12 = *plVar19;
              *plVar19 = lVar12 + -1;
              if (lVar12 + -1 == 0) {
                (**(code **)(plVar19[1] + 0x30))();
              }
              auStack_88._8_8_ = uVar10;
              auStack_88._0_8_ = pcVar18;
              aplStack_78[0] = plVar13;
            }
          }
        }
      }
    }
LAB_23e795d5d:
    if (aplStack_78[0] == (longlong *)0x0) goto LAB_23e7954d0;
  }
  plVar11 = aplStack_78[0];
  plVar19 = DAT_23ed6a4f8;
  if ((longlong *)aplStack_78[0][3] != plVar3) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar19 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar16 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar16;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    plVar19[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar12 = *(longlong *)(pcVar18 + 0x1f8);
    *(undefined4 *)((longlong)plVar19 + 0x24) = uVar20;
    *(undefined4 *)(plVar19 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar1 = plVar19[-1];
    puVar2 = *(undefined8 **)(lVar12 + 8);
    *puVar2 = plVar19 + -2;
    plVar19[-2] = lVar12;
    plVar19[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar12 + 8) = plVar19 + -2;
    plVar19[2] = (longlong)plVar11;
    *plVar11 = *plVar11 + 1;
    plVar11 = plVar19;
    if ((aplStack_78[0] != (longlong *)0x0) &&
       (*aplStack_78[0] = *aplStack_78[0] + -1, *aplStack_78[0] == 0)) {
      (**(code **)(aplStack_78[0][1] + 0x30))(aplStack_78[0]);
    }
  }
LAB_23e795e23:
  aplStack_78[0] = plVar11;
  FUN_23e8bba40(plVar3,"oooooo",pcVar21,plVar8,plVar9,plVar15,plStack_e0,pcVar22);
  if (_DAT_23eedac40 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedac40 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar12 + 0x28);
  plVar11 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar11 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar11 = aplStack_78[0];
  plVar3[0xf] = 0;
  uVar10 = auStack_88._0_8_;
  uVar4 = auStack_88._8_8_;
  auStack_88 = (undefined1  [16])0x0;
  aplStack_78[0] = (longlong *)0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if ((plStack_e0 != (longlong *)0x0) && (*plStack_e0 = *plStack_e0 + -1, *plStack_e0 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  if ((pcVar22 != (code *)0x0) &&
     (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
    (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
  }
  *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
  aplStack_78[0] = plVar11;
  auStack_88._0_8_ = uVar10;
  auStack_88._8_8_ = uVar4;
  if (*(longlong *)pcVar21 == 0) {
    (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
  }
  FUN_23a33aa70(param_1,auStack_88._0_8_,auStack_88._8_8_,aplStack_78[0]);
  return (code *)0x0;
}
