/* ===== 23e7d48b0 workers.fishing.meal_system:210 ===== */
/* ghidra_name=FUN_23e7d48b0 entry=23e7d48b0 size=9408 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7d48b0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  char cVar4;
  int iVar5;
  longlong *plVar6;
  longlong *plVar7;
  undefined8 uVar8;
  code *pcVar9;
  longlong lVar10;
  code *pcVar11;
  longlong *plVar12;
  longlong *plVar13;
  code *pcVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  undefined4 uVar20;
  longlong *plVar21;
  code *pcVar22;
  code *pcVar23;
  longlong *plStack_d8;
  longlong *plStack_c0;
  code *pcStack_98;
  undefined8 uStack_90;
  undefined1 auStack_88 [16];
  longlong *aplStack_78 [7];
  
  plVar6 = _DAT_23eedecb0;
  plVar21 = (longlong *)*param_3;
  aplStack_78[0] = (longlong *)0x0;
  auStack_88 = (undefined1  [16])0x0;
  if (_DAT_23eedecb0 == (longlong *)0x0) {
LAB_23e7d4915:
    _DAT_23eedecb0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedeca8,DAT_23eed7940);
  }
  else {
    lVar10 = *_DAT_23eedecb0;
    if (1 < lVar10) {
      *_DAT_23eedecb0 = lVar10 + -1;
      goto LAB_23e7d4915;
    }
    if (_DAT_23eedecb0[2] != 0) {
      *_DAT_23eedecb0 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e7d4915;
    }
  }
  plVar19 = _DAT_23eedecb0;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23eedecb0 + 9;
  lVar1 = *(longlong *)(lVar10 + 8);
  _DAT_23eedecb0[0xf] = lVar1;
  *(longlong **)(lVar10 + 8) = plVar6;
  if ((lVar1 != 0) &&
     (((*(char *)(lVar1 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar1 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar1 + 0x38))
       ) && (plVar19[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar1 + 0x28);
    *(longlong **)(plVar19[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar19 = *plVar19 + 1;
  *(undefined4 *)(plVar19 + 8) = 0;
  plVar6 = (longlong *)FUN_23e8bc2f0(plVar21,uRam000000023eed72e8);
  if (plVar6 == (longlong *)0x0) {
    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar6 = *(longlong **)(param_1 + 0x70);
    pcVar22 = (code *)0x0;
    plStack_c0 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar14 = (code *)0x0;
    plVar7 = (longlong *)0x0;
    uVar20 = 0xd4;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    pcVar11 = (code *)0x0;
    plVar15 = DAT_23ed6a4f8;
    goto joined_r0x00023e7d5620;
  }
  *(undefined4 *)(plVar19 + 5) = 0xd4;
  plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar6,DAT_23ed6cee0);
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  if (plVar7 == (longlong *)0x0) {
    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar6 = *(longlong **)(param_1 + 0x70);
    pcVar22 = (code *)0x0;
    plStack_c0 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar14 = (code *)0x0;
    pcVar11 = (code *)0x0;
    uVar20 = 0xd4;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar7 = (longlong *)0x0;
    plVar15 = DAT_23ed6a4f8;
    goto joined_r0x00023e7d5620;
  }
  iVar5 = FUN_23a35f020(plVar7);
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if (iVar5 == -1) {
    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    aplStack_78[0] = *(longlong **)(param_1 + 0x70);
    uVar20 = 0xd4;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    plVar6 = plVar19;
    plVar15 = plVar21;
    if (iVar5 == 0) {
      uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar17 = plRam000000023eed73c0;
      lVar10 = *(longlong *)(param_1 + 0x10);
      plVar7 = *(longlong **)(lVar10 + 0xe20);
      if (plVar7 == (longlong *)0x0) {
        plVar7 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar1 = plVar7[3];
        *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
        *(longlong *)(lVar10 + 0xe20) = lVar1;
        *plVar7 = 1;
      }
      pcVar11 = _PyRuntime_exref;
      plVar7[4] = 0;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
      lVar1 = plVar7[-1];
      puVar2 = *(undefined8 **)(lVar10 + 8);
      *puVar2 = plVar7 + -2;
      plVar7[-2] = lVar10;
      plVar7[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar10 + 8) = plVar7 + -2;
      uVar3 = uRam000000023eed72e8;
      *plVar17 = *plVar17 + 1;
      plVar7[3] = (longlong)plVar17;
      pcVar9 = (code *)FUN_23e8bc2f0(plVar21,uVar3);
      uVar3 = DAT_23ed6cd28;
      if (pcVar9 != (code *)0x0) {
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar17 == (longlong *)0x0) goto LAB_23e7d61d8;
          *plVar17 = *plVar17 + 1;
          DAT_23ed6a4c0 = plVar17;
        }
        uStack_90 = uVar3;
        pcStack_98 = pcVar9;
        lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_98);
        *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
        if (*(longlong *)pcVar9 == 0) {
          (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
        }
        if (lVar10 != 0) {
          plVar7[4] = lVar10;
          plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar7);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if (plVar6 != (longlong *)0x0) {
            *(undefined4 *)(plVar19 + 5) = 0xd5;
            plVar7 = (longlong *)FUN_23e914090(param_1,uVar8,plVar6);
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            if (plVar7 == (longlong *)0x0) {
              auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
              plVar6 = *(longlong **)(param_1 + 0x70);
              pcVar22 = (code *)0x0;
              plStack_c0 = (longlong *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              pcVar14 = (code *)0x0;
              pcVar11 = (code *)0x0;
              uVar20 = 0xd5;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar7 = (longlong *)0x0;
              plVar15 = DAT_23ed6a4f8;
              goto joined_r0x00023e7d5620;
            }
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            pcVar9 = _Py_FalseStruct_exref;
            pcVar22 = (code *)0x0;
            pcVar14 = (code *)0x0;
            plVar7 = (longlong *)0x0;
            plStack_c0 = (longlong *)0x0;
            pcVar11 = (code *)0x0;
            *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
LAB_23e7d4bca:
            lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar6 = *(longlong **)(lVar10 + 0x28);
            plVar19 = (longlong *)plVar6[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
            *(undefined4 *)(plVar6 + 8) = 0xffffffff;
            if (plVar19 != (longlong *)0x0) {
              plVar6[2] = 0;
              *plVar19 = *plVar19 + -1;
              if (*plVar19 == 0) {
                (**(code **)(plVar19[1] + 0x30))();
              }
            }
            *plVar6 = *plVar6 + -1;
            if (*plVar6 == 0) {
              (**(code **)(plVar6[1] + 0x30))(plVar6);
            }
            plVar6[0xf] = 0;
            goto LAB_23e7d4c43;
          }
          auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
          plVar6 = *(longlong **)(param_1 + 0x70);
          pcVar22 = (code *)0x0;
          plStack_c0 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar14 = (code *)0x0;
          plVar7 = (longlong *)0x0;
          uVar20 = 0xd5;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar11 = (code *)0x0;
          plVar15 = DAT_23ed6a4f8;
          goto joined_r0x00023e7d5620;
        }
      }
      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
      aplStack_78[0] = *(longlong **)(param_1 + 0x70);
      uVar20 = 0xd5;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
        uVar20 = 0xd5;
      }
    }
    else {
      uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
      plVar17 = plRam000000023eed73c8;
      lVar10 = *(longlong *)(param_1 + 0x10);
      plVar7 = *(longlong **)(lVar10 + 0xe20);
      if (plVar7 == (longlong *)0x0) {
        plVar7 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar1 = plVar7[3];
        *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
        *(longlong *)(lVar10 + 0xe20) = lVar1;
        *plVar7 = 1;
      }
      pcVar11 = _PyRuntime_exref;
      plVar7[4] = 0;
      lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
      lVar1 = plVar7[-1];
      puVar2 = *(undefined8 **)(lVar10 + 8);
      *puVar2 = plVar7 + -2;
      plVar7[-2] = lVar10;
      plVar7[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar10 + 8) = plVar7 + -2;
      uVar3 = uRam000000023eed72e8;
      *plVar17 = *plVar17 + 1;
      plVar7[3] = (longlong)plVar17;
      pcVar9 = (code *)FUN_23e8bc2f0(plVar21,uVar3);
      uVar3 = DAT_23ed6cd28;
      if (pcVar9 != (code *)0x0) {
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar17 != (longlong *)0x0) {
            *plVar17 = *plVar17 + 1;
            DAT_23ed6a4c0 = plVar17;
            goto LAB_23e7d4f1e;
          }
LAB_23e7d61d8:
          PyErr_PrintEx(0,0);
          Py_Exit(1);
          plVar19 = plVar6;
          pcVar11 = pcVar9;
          plVar21 = plVar15;
LAB_23e7d61eb:
          auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
          plVar6 = *(longlong **)(param_1 + 0x70);
          pcVar22 = (code *)0x0;
          plStack_c0 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar14 = (code *)0x0;
          plVar7 = (longlong *)0x0;
          uVar20 = 0xeb;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar15 = DAT_23ed6a4f8;
          goto joined_r0x00023e7d5620;
        }
LAB_23e7d4f1e:
        uStack_90 = uVar3;
        pcStack_98 = pcVar9;
        lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_98);
        *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
        if (*(longlong *)pcVar9 == 0) {
          (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
        }
        if (lVar10 != 0) {
          plVar7[4] = lVar10;
          plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar7);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          if (plVar6 == (longlong *)0x0) {
            auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar6 = *(longlong **)(param_1 + 0x70);
            pcVar22 = (code *)0x0;
            plStack_c0 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar14 = (code *)0x0;
            plVar7 = (longlong *)0x0;
            uVar20 = 0xd8;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar11 = (code *)0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e7d5620;
          }
          *(undefined4 *)(plVar19 + 5) = 0xd8;
          plVar7 = (longlong *)FUN_23e914090(param_1,uVar8);
          *plVar6 = *plVar6 + -1;
          if (*plVar6 == 0) {
            (**(code **)(plVar6[1] + 0x30))(plVar6);
          }
          if (plVar7 == (longlong *)0x0) {
            auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar6 = *(longlong **)(param_1 + 0x70);
            pcVar22 = (code *)0x0;
            plStack_c0 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar14 = (code *)0x0;
            pcVar11 = (code *)0x0;
            uVar20 = 0xd8;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar7 = (longlong *)0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e7d5620;
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          plVar6 = (longlong *)FUN_23e8bc2f0(plVar21,uRam000000023eed72b0);
          if (plVar6 == (longlong *)0x0) {
            auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
            plVar6 = *(longlong **)(param_1 + 0x70);
            pcVar22 = (code *)0x0;
            plStack_c0 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar14 = (code *)0x0;
            plVar7 = (longlong *)0x0;
            uVar20 = 0xdb;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar11 = (code *)0x0;
            plVar15 = DAT_23ed6a4f8;
            goto joined_r0x00023e7d5620;
          }
          iVar5 = FUN_23e913250(plVar6,uRam000000023eed7330);
          *plVar6 = *plVar6 + -1;
          if (*plVar6 == 0) {
            (**(code **)(plVar6[1] + 0x30))(plVar6);
          }
          if (iVar5 == -1) {
            auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
            aplStack_78[0] = *(longlong **)(param_1 + 0x70);
            uVar20 = 0xdb;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e7d5610;
          }
          if (iVar5 == 1) {
            pcVar11 = (code *)FUN_23e8d7870(param_1,uRam000000023eed73d0);
          }
          else {
            pcVar11 = (code *)FUN_23e8d7870(param_1,uRam000000023eed73d8);
          }
          plVar6 = (longlong *)FUN_23e94b990(pcVar11);
          plVar17 = (longlong *)FUN_23ebf7180(plVar6);
          *plVar6 = *plVar6 + -1;
          if (*plVar6 == 0) {
            (**(code **)(plVar6[1] + 0x30))(plVar6);
          }
          if (plVar17 == (longlong *)0x0) goto LAB_23e7d61eb;
          if (plVar21 == (longlong *)0x0) {
            lVar10 = plVar17[1];
            if (*(code **)(lVar10 + 0xe0) == (code *)0x0) {
              plStack_d8 = (longlong *)0x0;
              pcVar22 = (code *)0x0;
              pcVar9 = (code *)0x0;
              plStack_c0 = (longlong *)0x0;
              plVar15 = (longlong *)0x0;
LAB_23e7d5da0:
              PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                           *(undefined8 *)(lVar10 + 0x18));
              pcVar14 = pcVar9;
              plVar7 = plVar15;
            }
            else {
              plStack_d8 = (longlong *)(**(code **)(lVar10 + 0xe0))();
              if (plStack_d8 != (longlong *)0x0) {
                plVar13 = (longlong *)FUN_23a388310(plStack_d8);
                if (plVar13 == (longlong *)0x0) {
                  pcVar22 = (code *)0x0;
                  pcVar9 = (code *)0x0;
                  plVar15 = (longlong *)0x0;
                  plStack_c0 = (longlong *)0x0;
LAB_23e7d6568:
                  pcVar23 = *(code **)(param_1 + 0x60);
                  uVar8 = *(undefined8 *)(param_1 + 0x68);
                  plVar6 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar7 = plVar15;
                }
                else {
                  plVar7 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                  if ((plVar7 == (longlong *)0x0) &&
                     (plVar7 = (longlong *)FUN_23a3c1b70(param_1,auStack_88,0),
                     plVar7 == (longlong *)0x0)) {
                    pcVar22 = (code *)0x0;
                    pcVar9 = (code *)0x0;
                    plVar15 = (longlong *)0x0;
                    plStack_c0 = (longlong *)0x0;
                    pcVar14 = (code *)0x0;
                    plVar16 = plStack_c0;
                  }
                  else {
                    pcVar14 = (code *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                    if ((pcVar14 != (code *)0x0) ||
                       (pcVar14 = (code *)FUN_23a3c1b70(param_1,auStack_88,1),
                       pcVar14 != (code *)0x0)) {
                      cVar4 = FUN_23a3884a0(param_1,auStack_88,plVar13);
                      lVar10 = *plVar13;
                      if (cVar4 != '\0') {
                        *plVar13 = lVar10 + -1;
                        if (lVar10 + -1 == 0) {
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        if (*plVar7 == 0) {
                          (**(code **)(plVar7[1] + 0x30))(plVar7);
                        }
                        if (*(longlong *)pcVar14 == 0) {
                          (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
                        }
                        auStack_88._8_8_ =
                             PyUnicode_FromFormat
                                       ("cannot access local variable \'%U\' where it is not associated with a value"
                                        ,DAT_23eed70d0);
                        auStack_88._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
                        *(longlong *)auStack_88._0_8_ = *(longlong *)auStack_88._0_8_ + 1;
                        aplStack_78[0] = (longlong *)0x0;
                        if ((code *)auStack_88._0_8_ != _Py_NoneStruct_exref) {
                          FUN_23e91b1b0(param_1,auStack_88,auStack_88 + 8,aplStack_78);
                        }
                        pcVar22 = (code *)0x0;
                        plStack_c0 = (longlong *)0x0;
                        FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_88._8_8_);
                        uVar20 = 0xec;
                        plVar6 = aplStack_78[0];
                        pcVar23 = (code *)auStack_88._0_8_;
                        uVar8 = auStack_88._8_8_;
                        goto LAB_23e7d5910;
                      }
                    }
                    pcVar22 = (code *)0x0;
                    pcVar9 = (code *)0x0;
                    plVar15 = (longlong *)0x0;
                    plStack_c0 = (longlong *)0x0;
                    plVar16 = plStack_c0;
                  }
LAB_23e7d5f4d:
                  plStack_c0 = plVar16;
                  plVar6 = aplStack_78[0];
                  pcVar23 = (code *)auStack_88._0_8_;
                  uVar8 = auStack_88._8_8_;
                  aplStack_78[0] = (longlong *)0x0;
                  auStack_88 = (undefined1  [16])0x0;
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  aplStack_78[0] = (longlong *)0x0;
                  auStack_88 = (undefined1  [16])0x0;
                  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
                    (**(code **)(plVar7[1] + 0x30))(plVar7);
                  }
                  plVar7 = plVar15;
                  if ((pcVar14 != (code *)0x0) &&
                     (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0))
                  {
                    (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
                  }
                }
                pcVar14 = pcVar9;
                uVar20 = 0xeb;
                goto LAB_23e7d5910;
              }
              plStack_d8 = (longlong *)0x0;
              pcVar22 = (code *)0x0;
              plStack_c0 = (longlong *)0x0;
              pcVar14 = (code *)0x0;
              plVar7 = (longlong *)0x0;
            }
LAB_23e7d5dd9:
            cVar4 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
            if (cVar4 != '\0') {
              lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar6 = *(longlong **)(lVar10 + 0x28);
              plVar19 = (longlong *)plVar6[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
              *(undefined4 *)(plVar6 + 8) = 0xffffffff;
              if (plVar19 != (longlong *)0x0) {
                plVar6[2] = 0;
                *plVar19 = *plVar19 + -1;
                if (*plVar19 == 0) {
                  (**(code **)(plVar19[1] + 0x30))();
                }
              }
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              plVar6[0xf] = 0;
              if ((plStack_d8 != (longlong *)0x0) &&
                 (*plStack_d8 = *plStack_d8 + -1, *plStack_d8 == 0)) {
                (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
              }
              lVar10 = *plVar17;
              *plVar17 = lVar10 + -1;
              if (lVar10 + -1 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              pcVar9 = _Py_TrueStruct_exref;
              *(longlong *)_Py_TrueStruct_exref = *(longlong *)_Py_TrueStruct_exref + 1;
LAB_23e7d4c43:
              if ((pcVar11 != (code *)0x0) &&
                 (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
                (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
              }
              if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              if ((pcVar14 != (code *)0x0) &&
                 (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
                (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
              }
              if ((plStack_c0 != (longlong *)0x0) &&
                 (lVar10 = *plStack_c0, *plStack_c0 = lVar10 + -1, lVar10 + -1 == 0)) {
                (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
              }
              if ((pcVar22 != (code *)0x0) &&
                 (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
                (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
              }
              *plVar21 = *plVar21 + -1;
              if (*plVar21 == 0) {
                (**(code **)(plVar21[1] + 0x30))(plVar21);
                return pcVar9;
              }
              return pcVar9;
            }
            plVar6 = *(longlong **)(param_1 + 0x70);
            pcVar23 = *(code **)(param_1 + 0x60);
            uVar8 = *(undefined8 *)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            aplStack_78[0] = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            auStack_88 = (undefined1  [16])0x0;
            if (plStack_d8 != (longlong *)0x0) {
              uVar20 = 0xeb;
              goto LAB_23e7d5910;
            }
            uVar20 = 0xeb;
          }
          else {
            pcVar9 = (code *)0x0;
            plVar15 = (longlong *)0x0;
            plVar16 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            pcVar22 = (code *)0x0;
            do {
              lVar10 = plVar17[1];
              plStack_c0 = plVar16;
              if (*(code **)(lVar10 + 0xe0) == (code *)0x0) goto LAB_23e7d5da0;
              plVar12 = (longlong *)(**(code **)(lVar10 + 0xe0))();
              pcVar14 = pcVar9;
              plVar7 = plVar15;
              if (plVar12 == (longlong *)0x0) goto LAB_23e7d5dd9;
              if ((plStack_d8 != (longlong *)0x0) &&
                 (*plStack_d8 = *plStack_d8 + -1, *plStack_d8 == 0)) {
                (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
              }
              plVar13 = (longlong *)FUN_23a388310(plVar12);
              plStack_d8 = plVar12;
              if (plVar13 == (longlong *)0x0) goto LAB_23e7d6568;
              plVar7 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
              if ((plVar7 == (longlong *)0x0) &&
                 (plVar7 = (longlong *)FUN_23a3c1b70(param_1,auStack_88,0,2),
                 plVar7 == (longlong *)0x0)) {
                pcVar14 = (code *)0x0;
                goto LAB_23e7d5f4d;
              }
              plStack_c0 = (longlong *)auStack_88;
              pcVar14 = (code *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
              if ((pcVar14 == (code *)0x0) &&
                 (pcVar14 = (code *)FUN_23a3c1b70(param_1,plStack_c0,1,2), pcVar14 == (code *)0x0))
              goto LAB_23e7d5f4d;
              cVar4 = FUN_23a3884a0(param_1,plStack_c0,plVar13,2);
              lVar10 = *plVar13;
              if (cVar4 == '\0') goto LAB_23e7d5f4d;
              *plVar13 = lVar10 + -1;
              if (lVar10 + -1 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              lVar10 = *plVar7;
              *plVar7 = lVar10 + 1;
              if (plVar15 != (longlong *)0x0) {
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                  lVar10 = *plVar7 + -1;
                }
                else {
                  lVar10 = *plVar7 + -1;
                }
              }
              *plVar7 = lVar10;
              if (lVar10 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              lVar10 = *(longlong *)pcVar14;
              *(longlong *)pcVar14 = lVar10 + 1;
              if (pcVar9 != (code *)0x0) {
                *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
                if (*(longlong *)pcVar9 == 0) {
                  (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
                  lVar10 = *(longlong *)pcVar14 + -1;
                }
                else {
                  lVar10 = *(longlong *)pcVar14 + -1;
                }
              }
              *(longlong *)pcVar14 = lVar10;
              if (lVar10 == 0) {
                (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
              }
              plVar6 = (longlong *)FUN_23e8bc2f0(plVar21,uRam000000023eed72e8);
              if (plVar6 == (longlong *)0x0) {
LAB_23e7d622a:
                pcVar23 = *(code **)(param_1 + 0x60);
                plVar6 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar20 = 0xec;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plStack_c0 = plVar16;
                uVar8 = *(undefined8 *)(param_1 + 0x68);
                goto LAB_23e7d5910;
              }
              plVar13 = (longlong *)FUN_23e8c6f80(plVar6,pcVar14);
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              if (plVar13 == (longlong *)0x0) goto LAB_23e7d622a;
              if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              *(undefined4 *)(plVar19 + 5) = 0xed;
              plVar6 = (longlong *)FUN_23e91bfe0(param_1,plVar13,DAT_23ed6cee0);
              if (plVar6 == (longlong *)0x0) {
LAB_23e7d6277:
                pcVar23 = *(code **)(param_1 + 0x60);
                plVar6 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar20 = 0xed;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_c0 = plVar13;
                uVar8 = *(undefined8 *)(param_1 + 0x68);
                goto LAB_23e7d5910;
              }
              iVar5 = FUN_23a35f020(plVar6);
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              if (iVar5 == -1) goto LAB_23e7d6277;
              if (iVar5 == 0) {
                uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
                plVar6 = plRam000000023eed73e0;
                lVar10 = *(longlong *)(param_1 + 0x10);
                plVar16 = *(longlong **)(lVar10 + 0xe28);
                if (plVar16 == (longlong *)0x0) {
                  plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                }
                else {
                  lVar1 = plVar16[3];
                  *(int *)(lVar10 + 0xec0) = *(int *)(lVar10 + 0xec0) + -1;
                  *(longlong *)(lVar10 + 0xe28) = lVar1;
                  *plVar16 = 1;
                }
                pcVar9 = _PyRuntime_exref;
                *(undefined1 (*) [16])(plVar16 + 4) = (undefined1  [16])0x0;
                lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar9 + 0x1f8) + 0x10) + 0x2e8);
                lVar1 = plVar16[-1];
                puVar2 = *(undefined8 **)(lVar10 + 8);
                *puVar2 = plVar16 + -2;
                plVar16[-2] = lVar10;
                plVar16[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
                *(longlong **)(lVar10 + 8) = plVar16 + -2;
                *plVar6 = *plVar6 + 1;
                plVar16[3] = (longlong)plVar6;
                uVar3 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar18 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  plVar6 = plVar19;
                  pcVar9 = pcVar11;
                  plVar15 = plVar21;
                  if (plVar18 == (longlong *)0x0) goto LAB_23e7d61d8;
                  *plVar18 = *plVar18 + 1;
                  DAT_23ed6a4c0 = plVar18;
                }
                uStack_90 = uVar3;
                pcStack_98 = pcVar14;
                lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_98);
                if (lVar10 == 0) {
                  auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0(plVar16);
                    uVar20 = 0xee;
                    plVar6 = aplStack_78[0];
                    plStack_c0 = plVar13;
                    pcVar23 = (code *)auStack_88._0_8_;
                    uVar8 = auStack_88._8_8_;
                  }
                  else {
                    uVar20 = 0xee;
                    plVar6 = aplStack_78[0];
                    plStack_c0 = plVar13;
                    pcVar23 = (code *)auStack_88._0_8_;
                    uVar8 = auStack_88._8_8_;
                  }
                  goto LAB_23e7d5910;
                }
                plVar16[4] = lVar10;
                plVar6 = plRam000000023eed73e8;
                *plRam000000023eed73e8 = *plRam000000023eed73e8 + 1;
                plVar16[5] = (longlong)plVar6;
                plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                if (plVar6 != (longlong *)0x0) {
                  *(undefined4 *)(plVar19 + 5) = 0xee;
                  plVar15 = (longlong *)FUN_23e914090(param_1,uVar8);
                  *plVar6 = *plVar6 + -1;
                  if (*plVar6 == 0) {
                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                  }
                  if (plVar15 != (longlong *)0x0) {
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    lVar10 = *(longlong *)_Py_FalseStruct_exref;
LAB_23e7d6758:
                    pcVar9 = _Py_FalseStruct_exref;
                    *(longlong *)_Py_FalseStruct_exref = lVar10 + 1;
                    lVar10 = *plVar12;
                    *plVar12 = lVar10 + -1;
                    if (lVar10 + -1 == 0) {
                      (**(code **)(plVar12[1] + 0x30))();
                    }
                    lVar10 = *plVar17;
                    *plVar17 = lVar10 + -1;
                    plStack_c0 = plVar13;
                    if (lVar10 + -1 == 0) {
                      (**(code **)(plVar17[1] + 0x30))();
                    }
                    goto LAB_23e7d4bca;
                  }
                }
                plVar6 = *(longlong **)(param_1 + 0x70);
                pcVar23 = *(code **)(param_1 + 0x60);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar20 = 0xee;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plStack_c0 = plVar13;
                uVar8 = *(undefined8 *)(param_1 + 0x68);
                goto LAB_23e7d5910;
              }
              lVar10 = FUN_23e8de200();
              if (lVar10 == 0) {
                FUN_23e915740(param_1,plStack_c0,uRam000000023eed71e0);
                uVar20 = 0xf1;
                plVar6 = aplStack_78[0];
                plStack_c0 = plVar13;
                pcVar23 = (code *)auStack_88._0_8_;
                uVar8 = auStack_88._8_8_;
                goto LAB_23e7d5910;
              }
              plVar6 = (longlong *)FUN_23e8bc2f0(lVar10,uRam000000023eed73f0);
              if (plVar6 == (longlong *)0x0) {
LAB_23e7d62c4:
                pcVar23 = *(code **)(param_1 + 0x60);
                plVar6 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar20 = 0xf1;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_c0 = plVar13;
                uVar8 = *(undefined8 *)(param_1 + 0x68);
                goto LAB_23e7d5910;
              }
              plVar15 = (longlong *)FUN_23e8bd350(plVar13);
              if (plVar15 == (longlong *)0x0) {
                auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar6 = *plVar6 + -1;
                if (*plVar6 == 0) {
                  (**(code **)(plVar6[1] + 0x30))(plVar6);
                  uVar20 = 0xf1;
                  plVar6 = aplStack_78[0];
                  plStack_c0 = plVar13;
                  pcVar23 = (code *)auStack_88._0_8_;
                  uVar8 = auStack_88._8_8_;
                }
                else {
                  uVar20 = 0xf1;
                  plVar6 = aplStack_78[0];
                  plStack_c0 = plVar13;
                  pcVar23 = (code *)auStack_88._0_8_;
                  uVar8 = auStack_88._8_8_;
                }
                goto LAB_23e7d5910;
              }
              *(undefined4 *)(plVar19 + 5) = 0xf1;
              pcVar9 = (code *)FUN_23e914090(param_1,plVar6,plVar15);
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              if (pcVar9 == (code *)0x0) goto LAB_23e7d62c4;
              if ((pcVar22 != (code *)0x0) &&
                 (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
                (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
              }
              if (pcVar9 == _Py_NoneStruct_exref) {
                uVar8 = FUN_23a3a0d40(DAT_23ed6cf28);
                plVar6 = plRam000000023eed73f8;
                lVar10 = *(longlong *)(param_1 + 0x10);
                plVar16 = *(longlong **)(lVar10 + 0xe20);
                if (plVar16 == (longlong *)0x0) {
                  plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar1 = plVar16[3];
                  *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
                  *(longlong *)(lVar10 + 0xe20) = lVar1;
                  *plVar16 = 1;
                }
                pcVar22 = _PyRuntime_exref;
                plVar16[4] = 0;
                lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar22 + 0x1f8) + 0x10) + 0x2e8)
                ;
                lVar1 = plVar16[-1];
                puVar2 = *(undefined8 **)(lVar10 + 8);
                *puVar2 = plVar16 + -2;
                plVar16[-2] = lVar10;
                plVar16[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
                *(longlong **)(lVar10 + 8) = plVar16 + -2;
                *plVar6 = *plVar6 + 1;
                plVar16[3] = (longlong)plVar6;
                uVar3 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 == (longlong *)0x0) {
                  plVar18 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                  plVar6 = plVar19;
                  pcVar9 = pcVar11;
                  plVar15 = plVar21;
                  if (plVar18 == (longlong *)0x0) goto LAB_23e7d61d8;
                  *plVar18 = *plVar18 + 1;
                  DAT_23ed6a4c0 = plVar18;
                }
                uStack_90 = uVar3;
                pcStack_98 = pcVar14;
                lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_98);
                if (lVar10 == 0) {
                  auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0(plVar16);
                    uVar20 = 0xf3;
                    plVar6 = aplStack_78[0];
                    plStack_c0 = plVar13;
                    pcVar22 = _Py_NoneStruct_exref;
                    pcVar23 = (code *)auStack_88._0_8_;
                    uVar8 = auStack_88._8_8_;
                  }
                  else {
                    uVar20 = 0xf3;
                    plVar6 = aplStack_78[0];
                    plStack_c0 = plVar13;
                    pcVar22 = _Py_NoneStruct_exref;
                    pcVar23 = (code *)auStack_88._0_8_;
                    uVar8 = auStack_88._8_8_;
                  }
                }
                else {
                  plVar16[4] = lVar10;
                  plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                  }
                  if (plVar6 != (longlong *)0x0) {
                    *(undefined4 *)(plVar19 + 5) = 0xf3;
                    plVar15 = (longlong *)FUN_23e914090(param_1,uVar8);
                    *plVar6 = *plVar6 + -1;
                    if (*plVar6 == 0) {
                      (**(code **)(plVar6[1] + 0x30))(plVar6);
                    }
                    if (plVar15 != (longlong *)0x0) {
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        FUN_23a334bc0(plVar15);
                      }
                      lVar10 = *(longlong *)_Py_FalseStruct_exref;
                      pcVar22 = _Py_NoneStruct_exref;
                      goto LAB_23e7d6758;
                    }
                  }
                  pcVar23 = *(code **)(param_1 + 0x60);
                  plVar6 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcVar22 = _Py_NoneStruct_exref;
                  uVar20 = 0xf3;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plStack_c0 = plVar13;
                  uVar8 = *(undefined8 *)(param_1 + 0x68);
                }
                goto LAB_23e7d5910;
              }
              plVar6 = (longlong *)FUN_23e8bc2f0(plVar21,uRam000000023eed72d0);
              pcVar22 = pcVar9;
              if (plVar6 == (longlong *)0x0) {
LAB_23e7d6311:
                pcVar23 = *(code **)(param_1 + 0x60);
                plVar6 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar20 = 0xf6;
                plStack_c0 = plVar13;
                uVar8 = *(undefined8 *)(param_1 + 0x68);
                goto LAB_23e7d5910;
              }
              cVar4 = FUN_23a39bc50(param_1,plVar6,plVar7,pcVar9);
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              if (cVar4 == '\0') goto LAB_23e7d6311;
              plVar15 = (longlong *)FUN_23a3a0d40(DAT_23ed6cf28);
              plVar6 = plRam000000023eed7400;
              lVar10 = *(longlong *)(param_1 + 0x10);
              plVar16 = *(longlong **)(lVar10 + 0xe20);
              if (plVar16 == (longlong *)0x0) {
                plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
              }
              else {
                lVar1 = plVar16[3];
                *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
                *(longlong *)(lVar10 + 0xe20) = lVar1;
                *plVar16 = 1;
              }
              pcVar23 = _PyRuntime_exref;
              plVar16[4] = 0;
              lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar23 + 0x1f8) + 0x10) + 0x2e8);
              lVar1 = plVar16[-1];
              puVar2 = *(undefined8 **)(lVar10 + 8);
              *puVar2 = plVar16 + -2;
              plVar16[-2] = lVar10;
              plVar16[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
              *(longlong **)(lVar10 + 8) = plVar16 + -2;
              *plVar6 = *plVar6 + 1;
              plVar16[3] = (longlong)plVar6;
              uVar8 = DAT_23ed6cd28;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar12 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                plVar6 = plVar13;
                if (plVar12 == (longlong *)0x0) goto LAB_23e7d61d8;
                *plVar12 = *plVar12 + 1;
                DAT_23ed6a4c0 = plVar12;
              }
              uStack_90 = uVar8;
              pcStack_98 = pcVar14;
              lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_98);
              if (lVar10 == 0) {
                auStack_88._0_8_ = *(undefined8 *)(param_1 + 0x60);
                auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                aplStack_78[0] = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                  uVar20 = 0xf7;
                  plVar6 = aplStack_78[0];
                  plStack_c0 = plVar13;
                  pcVar23 = (code *)auStack_88._0_8_;
                  uVar8 = auStack_88._8_8_;
                }
                else {
                  uVar20 = 0xf7;
                  plVar6 = aplStack_78[0];
                  plStack_c0 = plVar13;
                  pcVar23 = (code *)auStack_88._0_8_;
                  uVar8 = auStack_88._8_8_;
                }
                goto LAB_23e7d5910;
              }
              plVar16[4] = lVar10;
              plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              if (plVar6 == (longlong *)0x0) {
LAB_23e7d6361:
                pcVar23 = *(code **)(param_1 + 0x60);
                plVar6 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar20 = 0xf7;
                plStack_c0 = plVar13;
                uVar8 = *(undefined8 *)(param_1 + 0x68);
                goto LAB_23e7d5910;
              }
              *(undefined4 *)(plVar19 + 5) = 0xf7;
              plVar15 = (longlong *)FUN_23e914090(param_1,plVar15);
              *plVar6 = *plVar6 + -1;
              if (*plVar6 == 0) {
                (**(code **)(plVar6[1] + 0x30))(plVar6);
              }
              if (plVar15 == (longlong *)0x0) goto LAB_23e7d6361;
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              lVar10 = *(longlong *)(param_1 + 0x10);
              if ((((*(int *)(*(longlong *)(lVar10 + 0x28) + 0x160) != 0) ||
                   (*(int *)(lVar10 + 0x78) != 0)) && (iVar5 = Py_MakePendingCalls(), iVar5 < 0)) &&
                 (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e7d58d0;
              if (*(int *)(lVar10 + 0x68) == 0) {
                plVar6 = *(longlong **)(param_1 + 0x90);
              }
              else {
                PyEval_SaveThread();
                PyEval_AcquireThread(param_1);
                plVar6 = *(longlong **)(param_1 + 0x90);
              }
              pcVar9 = pcVar14;
              plVar15 = plVar7;
              plVar16 = plVar13;
            } while (plVar6 == (longlong *)0x0);
            plVar15 = *(longlong **)(param_1 + 0x60);
            plVar16 = *(longlong **)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x90) = 0;
            plVar12 = *(longlong **)(param_1 + 0x70);
            *(longlong **)(param_1 + 0x60) = plVar6;
            *plVar6 = *plVar6 + 1;
            *(undefined8 *)(param_1 + 0x68) = 0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
              (**(code **)(plVar15[1] + 0x30))();
            }
            if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
              (**(code **)(plVar16[1] + 0x30))(plVar16);
            }
            if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
LAB_23e7d58d0:
            plVar6 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar23 = *(code **)(param_1 + 0x60);
            uVar20 = 0xeb;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plStack_c0 = plVar13;
            uVar8 = *(undefined8 *)(param_1 + 0x68);
LAB_23e7d5910:
            aplStack_78[0] = (longlong *)0x0;
            auStack_88 = (undefined1  [16])0x0;
            lVar10 = *plStack_d8;
            *plStack_d8 = lVar10 + -1;
            if (lVar10 + -1 == 0) {
              (**(code **)(plStack_d8[1] + 0x30))();
            }
          }
          lVar10 = *plVar17;
          *plVar17 = lVar10 + -1;
          if (lVar10 + -1 == 0) {
            (**(code **)(plVar17[1] + 0x30))();
          }
          auStack_88._8_8_ = uVar8;
          auStack_88._0_8_ = pcVar23;
          plVar15 = DAT_23ed6a4f8;
          goto joined_r0x00023e7d5620;
        }
      }
      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
      aplStack_78[0] = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      uVar20 = 0xd8;
    }
  }
LAB_23e7d5610:
  pcVar22 = (code *)0x0;
  plStack_c0 = (longlong *)0x0;
  pcVar14 = (code *)0x0;
  plVar7 = (longlong *)0x0;
  pcVar11 = (code *)0x0;
  plVar15 = DAT_23ed6a4f8;
  plVar6 = aplStack_78[0];
joined_r0x00023e7d5620:
  DAT_23ed6a4f8 = plVar15;
  aplStack_78[0] = plVar6;
  if (plVar6 == (longlong *)0x0) {
    if (plVar15 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar15;
      *plVar15 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar15[2] = 0;
    plVar15[3] = (longlong)plVar19;
    *plVar19 = *plVar19 + 1;
    lVar10 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar20;
    lVar10 = *(longlong *)(lVar10 + 0x10);
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(lVar10 + 0x2e8);
    lVar1 = plVar15[-1];
    puVar2 = *(undefined8 **)(lVar10 + 8);
    *puVar2 = plVar15 + -2;
    plVar15[-2] = lVar10;
    plVar15[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar10 + 8) = plVar15 + -2;
    plVar6 = plVar15;
    if ((aplStack_78[0] != (longlong *)0x0) &&
       (*aplStack_78[0] = *aplStack_78[0] + -1, *aplStack_78[0] == 0)) {
      (**(code **)(aplStack_78[0][1] + 0x30))(aplStack_78[0]);
    }
  }
  else if ((longlong *)plVar6[3] != plVar19) {
    if (plVar15 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar15;
      *plVar15 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar15[3] = (longlong)plVar19;
    *plVar19 = *plVar19 + 1;
    lVar10 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar20;
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
    lVar1 = plVar15[-1];
    puVar2 = *(undefined8 **)(lVar10 + 8);
    *puVar2 = plVar15 + -2;
    plVar15[-2] = lVar10;
    plVar15[-1] = (ulonglong)((uint)lVar1 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar10 + 8) = plVar15 + -2;
    plVar15[2] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    plVar6 = plVar15;
    if ((aplStack_78[0] != (longlong *)0x0) &&
       (*aplStack_78[0] = *aplStack_78[0] + -1, *aplStack_78[0] == 0)) {
      (**(code **)(aplStack_78[0][1] + 0x30))(aplStack_78[0]);
    }
  }
  aplStack_78[0] = plVar6;
  FUN_23e8bba40(plVar19,"oooooo",plVar21,pcVar11,plVar7,pcVar14,plStack_c0,pcVar22);
  if (_DAT_23eedecb0 == plVar19) {
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    _DAT_23eedecb0 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar6 = *(longlong **)(lVar10 + 0x28);
  plVar19 = (longlong *)plVar6[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar6 + 8) = 0xffffffff;
  if (plVar19 != (longlong *)0x0) {
    plVar6[2] = 0;
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))();
    }
  }
  *plVar6 = *plVar6 + -1;
  if (*plVar6 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  plVar19 = aplStack_78[0];
  plVar6[0xf] = 0;
  uVar8 = auStack_88._0_8_;
  uVar3 = auStack_88._8_8_;
  auStack_88 = (undefined1  [16])0x0;
  aplStack_78[0] = (longlong *)0x0;
  if ((pcVar11 != (code *)0x0) &&
     (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
    (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
  }
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((pcVar14 != (code *)0x0) &&
     (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
    (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
  }
  if ((plStack_c0 != (longlong *)0x0) && (*plStack_c0 = *plStack_c0 + -1, *plStack_c0 == 0)) {
    (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
  }
  if ((pcVar22 != (code *)0x0) &&
     (*(longlong *)pcVar22 = *(longlong *)pcVar22 + -1, *(longlong *)pcVar22 == 0)) {
    (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
  }
  *plVar21 = *plVar21 + -1;
  aplStack_78[0] = plVar19;
  auStack_88._0_8_ = uVar8;
  auStack_88._8_8_ = uVar3;
  if (*plVar21 == 0) {
    (**(code **)(plVar21[1] + 0x30))(plVar21);
  }
  FUN_23a33aa70(param_1,auStack_88._0_8_,auStack_88._8_8_,aplStack_78[0]);
  return (code *)0x0;
}
