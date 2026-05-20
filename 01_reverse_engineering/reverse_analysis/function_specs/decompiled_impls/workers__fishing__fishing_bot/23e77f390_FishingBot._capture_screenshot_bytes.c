/* ===== 23e77f390 workers.fishing.fishing_bot:FishingBot._capture_screenshot_bytes ===== */
/* ghidra_name=FUN_23e77f390 entry=23e77f390 size=6105 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code ******* FUN_23e77f390(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  code ***pppcVar2;
  code *****pppppcVar3;
  longlong lVar4;
  undefined8 *puVar5;
  code ******ppppppcVar6;
  code *****pppppcVar7;
  int iVar8;
  longlong *plVar9;
  code *******pppppppcVar10;
  code *****pppppcVar11;
  undefined8 uVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong *plVar15;
  longlong *plVar16;
  code ****ppppcVar17;
  code ******ppppppcVar18;
  longlong *plVar19;
  code ******ppppppcVar20;
  undefined4 uVar21;
  longlong *unaff_RBP;
  code *******pppppppcVar22;
  longlong *unaff_R12;
  code ******unaff_R14;
  code *****pppppcVar23;
  undefined8 uVar24;
  longlong *plStack_108;
  longlong *plStack_100;
  code *pcStack_f8;
  code *******pppppppcStack_e8;
  undefined1 auStack_c8 [16];
  code ******appppppcStack_b8 [2];
  undefined8 uStack_a8;
  undefined8 uStack_a0;
  code *****pppppcStack_98;
  code *******pppppppcStack_88;
  longlong *plStack_80;
  code *pcStack_78;
  undefined8 uStack_70;
  undefined8 uStack_68;
  
  pppppcVar23 = _DAT_23eedad10;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eedad10 == (code *****)0x0) {
LAB_23e77f3d5:
    _DAT_23eedad10 = (code *****)FUN_23e91f3b0(param_1,_DAT_23eedafc0,DAT_23eedaeb8,0x38);
  }
  else {
    ppppcVar17 = *_DAT_23eedad10;
    if (1 < (longlong)ppppcVar17) {
      *_DAT_23eedad10 = (code ****)((longlong)ppppcVar17 + -1);
      goto LAB_23e77f3d5;
    }
    if (_DAT_23eedad10[2] != (code ****)0x0) {
      *_DAT_23eedad10 = (code ****)((longlong)ppppcVar17 + -1);
      if ((code ****)((longlong)ppppcVar17 + -1) == (code ****)0x0) {
        (*(code *)pppppcVar23[1][6])(pppppcVar23);
      }
      goto LAB_23e77f3d5;
    }
  }
  pppppcVar7 = _DAT_23eedad10;
  lVar14 = *(longlong *)(param_1 + 0x38);
  pppppcVar23 = _DAT_23eedad10 + 9;
  ppppcVar17 = *(code *****)(lVar14 + 8);
  _DAT_23eedad10[0xf] = ppppcVar17;
  *(code ******)(lVar14 + 8) = pppppcVar23;
  if ((ppppcVar17 != (code ****)0x0) &&
     (((*(char *)((longlong)ppppcVar17 + 0x45) == '\x01' ||
       ((code ***)((longlong)ppppcVar17[4] + (longlong)*(int *)(ppppcVar17[4] + 0x15) * 2 + 0xb8) <=
        ppppcVar17[7])) && (pppppcVar7[0xe] != (code ****)0x0)))) {
    pppcVar2 = ppppcVar17[5];
    pppppcVar7[0xe][2] = pppcVar2;
    if (pppcVar2 != (code ***)0x0) {
      *pppcVar2 = (code **)((longlong)*pppcVar2 + 1);
    }
  }
  pcStack_78 = _Py_NoneStruct_exref;
  *pppppcVar7 = (code ****)((longlong)*pppppcVar7 + 1);
  *(undefined4 *)(pppppcVar7 + 8) = 0;
  uStack_70 = _DAT_23eed9800;
  pppppppcStack_88 = _DAT_23eed97f8;
  *(undefined4 *)(pppppcVar7 + 5) = 0x65c;
  pppppppcVar22 = (code *******)&DAT_23ed6a498;
  plStack_80 = DAT_23eed8950;
  uStack_68 = DAT_23ed6ccf0;
  if (DAT_23ed6a498 == (longlong *)0x0) {
    plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
      DAT_23ed6a498 = plVar9;
      goto LAB_23e77f4ba;
    }
LAB_23e780a30:
    iVar8 = 0;
    PyErr_PrintEx(0);
    Py_Exit(1);
LAB_23e780a43:
    ppppppcVar20 = (code ******)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
LAB_23e77f4ba:
    pppppppcStack_e8 = (code *******)&pppppppcStack_88;
    plVar9 = (longlong *)FUN_23e95b390(param_1,DAT_23ed6a498,pppppppcStack_e8);
    pcStack_f8 = _PyRuntime_exref;
    if (plVar9 == (longlong *)0x0) {
      unaff_RBP = (longlong *)0x0;
      unaff_R12 = (longlong *)0x0;
      uVar12 = *(undefined8 *)(param_1 + 0x60);
      uVar24 = *(undefined8 *)(param_1 + 0x68);
      pppppcVar23 = *(code ******)(param_1 + 0x70);
      plStack_108 = (longlong *)0x0;
      uVar21 = 0x65c;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plStack_100 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pppppppcVar22 = (code *******)0x0;
    }
    else {
      if (((code *)plVar9[1] == PyModule_Type_exref) ||
         (iVar8 = PyType_IsSubtype(), uVar12 = _DAT_23eed9808, iVar8 != 0)) {
        uVar24 = _DAT_23eed9808;
        plVar15 = DAT_23eed8950;
        uVar12 = DAT_23ed6ccf0;
        unaff_R12 = (longlong *)PyObject_GetAttr(plVar9,_DAT_23eed9808);
        if (unaff_R12 == (longlong *)0x0) {
          unaff_R12 = (longlong *)FUN_23e970390(param_1,plVar9,plVar15,uVar24,uVar12);
          goto LAB_23e7807c1;
        }
LAB_23e77f561:
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
      }
      else {
        unaff_R12 = (longlong *)PyObject_GetAttr(plVar9,_DAT_23eed9808);
        if (unaff_R12 != (longlong *)0x0) goto LAB_23e77f561;
        unaff_R12 = (longlong *)FUN_23e8d2cf0(param_1,plVar9,uVar12);
LAB_23e7807c1:
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (unaff_R12 == (longlong *)0x0) {
          pcStack_f8 = _PyRuntime_exref;
          unaff_RBP = (longlong *)0x0;
          pppppppcVar22 = (code *******)0x0;
          uVar12 = *(undefined8 *)(param_1 + 0x60);
          uVar24 = *(undefined8 *)(param_1 + 0x68);
          pppppcVar23 = *(code ******)(param_1 + 0x70);
          plStack_108 = (longlong *)0x0;
          uVar21 = 0x65c;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_100 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e77f96e;
        }
      }
      plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
      pcStack_f8 = _PyRuntime_exref;
      if (plVar9 == (longlong *)0x0) {
        pppppcVar23 = *(code ******)(param_1 + 0x70);
        uVar12 = *(undefined8 *)(param_1 + 0x60);
        uVar24 = *(undefined8 *)(param_1 + 0x68);
        pppppppcVar22 = (code *******)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar21 = 0x65e;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_108 = (longlong *)0x0;
        plStack_100 = (longlong *)0x0;
        unaff_RBP = (longlong *)0x0;
      }
      else {
        *(undefined4 *)(pppppcVar7 + 5) = 0x65e;
        pppppppcVar22 = (code *******)FUN_23e91bfe0(param_1,plVar9,DAT_23eed8a98);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        pcStack_f8 = _PyRuntime_exref;
        if (pppppppcVar22 == (code *******)0x0) {
          uVar12 = *(undefined8 *)(param_1 + 0x60);
          uVar24 = *(undefined8 *)(param_1 + 0x68);
          pppppcVar23 = *(code ******)(param_1 + 0x70);
          unaff_RBP = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar21 = 0x65e;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_108 = (longlong *)0x0;
          plStack_100 = (longlong *)0x0;
        }
        else {
          if (pppppppcVar22 == (code *******)_Py_NoneStruct_exref) {
            *pppppppcVar22 = (code ******)((longlong)*pppppppcVar22 + 1);
            unaff_RBP = (longlong *)0x0;
            plStack_108 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
            pppppppcVar10 = pppppppcVar22;
            goto LAB_23e77fc73;
          }
          lVar14 = FUN_23e8dfd30();
          if (lVar14 == 0) {
            FUN_23e915740(param_1,&uStack_a8,_DAT_23eed9608);
            unaff_RBP = (longlong *)0x0;
            pppppcVar23 = pppppcStack_98;
            uVar12 = uStack_a8;
            uVar24 = uStack_a0;
LAB_23e7808e9:
            uVar21 = 0x663;
            plStack_108 = (longlong *)0x0;
            plStack_100 = (longlong *)0x0;
            pcStack_f8 = _PyRuntime_exref;
          }
          else {
            plVar9 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23eed9810);
            pcStack_f8 = _PyRuntime_exref;
            if (plVar9 == (longlong *)0x0) {
              uVar12 = *(undefined8 *)(param_1 + 0x60);
              uVar24 = *(undefined8 *)(param_1 + 0x68);
              pppppcVar23 = *(code ******)(param_1 + 0x70);
              unaff_RBP = (longlong *)0x0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar21 = 0x663;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_108 = (longlong *)0x0;
              plStack_100 = (longlong *)0x0;
            }
            else {
              lVar14 = FUN_23e8dfd30();
              if (lVar14 == 0) {
                FUN_23e915740(param_1,&uStack_a8,_DAT_23eed9608);
                lVar14 = *plVar9;
                *plVar9 = lVar14 + -1;
                unaff_RBP = (longlong *)0x0;
                pppppcVar23 = pppppcStack_98;
                uVar12 = uStack_a8;
                uVar24 = uStack_a0;
                if (lVar14 + -1 == 0) {
                  (**(code **)(plVar9[1] + 0x30))();
                }
                goto LAB_23e7808e9;
              }
              plVar15 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23eed9818);
              if (plVar15 == (longlong *)0x0) {
                uVar12 = *(undefined8 *)(param_1 + 0x60);
                uVar24 = *(undefined8 *)(param_1 + 0x68);
                pppppcVar23 = *(code ******)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                lVar14 = *plVar9;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *plVar9 = lVar14 + -1;
                if (lVar14 + -1 == 0) {
                  (**(code **)(plVar9[1] + 0x30))();
                }
                unaff_RBP = (longlong *)0x0;
                uVar21 = 0x663;
                plStack_100 = (longlong *)0x0;
                pcStack_f8 = _PyRuntime_exref;
                plStack_108 = (longlong *)0x0;
              }
              else {
                *(undefined4 *)(pppppcVar7 + 5) = 0x663;
                pppppppcStack_88 = pppppppcVar22;
                plStack_80 = plVar15;
                unaff_RBP = (longlong *)FUN_23e94ed00(param_1,plVar9,pppppppcStack_e8);
                lVar14 = *plVar9;
                *plVar9 = lVar14 + -1;
                if (lVar14 + -1 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                lVar14 = *plVar15;
                *plVar15 = lVar14 + -1;
                if (lVar14 + -1 == 0) {
                  (**(code **)(plVar15[1] + 0x30))();
                }
                if (unaff_RBP == (longlong *)0x0) {
                  pppppcVar23 = *(code ******)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar12 = *(undefined8 *)(param_1 + 0x60);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  uVar24 = *(undefined8 *)(param_1 + 0x68);
                  goto LAB_23e7808e9;
                }
                *(undefined4 *)(pppppcVar7 + 5) = 0x666;
                plStack_100 = (longlong *)FUN_23e915840(param_1,unaff_R12,_DAT_23eed9820,unaff_RBP);
                pcStack_f8 = _PyRuntime_exref;
                if (plStack_100 == (longlong *)0x0) {
                  uVar12 = *(undefined8 *)(param_1 + 0x60);
                  uVar24 = *(undefined8 *)(param_1 + 0x68);
                  plStack_108 = (longlong *)0x0;
                  pppppcVar23 = *(code ******)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  uVar21 = 0x666;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                }
                else {
                  if ((DAT_23ed6dd68 == 0) &&
                     (DAT_23ed6dd68 = PyImport_ImportModule(&DAT_23ec5e016), DAT_23ed6dd68 == 0)) {
                    FUN_23e9364c0("%s : %s\n","IMPORT_HARD_IO",
                                  "\"Unexpected failure of hard import of \'io\'\"");
                    /* WARNING: Subroutine does not return */
                    abort();
                  }
                  plVar9 = (longlong *)FUN_23e8bc2f0(DAT_23ed6dd68,_DAT_23eed9828);
                  *(undefined4 *)(pppppcVar7 + 5) = 0x667;
                  plStack_108 = (longlong *)FUN_23e91a870(param_1,plVar9);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  pcStack_f8 = _PyRuntime_exref;
                  if (plStack_108 == (longlong *)0x0) {
                    uVar12 = *(undefined8 *)(param_1 + 0x60);
                    uVar24 = *(undefined8 *)(param_1 + 0x68);
                    uVar21 = 0x667;
                    pppppcVar23 = *(code ******)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                  }
                  else {
                    plVar9 = (longlong *)FUN_23e8bc2f0(plStack_100,_DAT_23eed9830);
                    pcStack_f8 = _PyRuntime_exref;
                    if (plVar9 == (longlong *)0x0) {
                      uVar12 = *(undefined8 *)(param_1 + 0x60);
                      uVar24 = *(undefined8 *)(param_1 + 0x68);
                      uVar21 = 0x668;
                      pppppcVar23 = *(code ******)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                    }
                    else {
                      lVar14 = *(longlong *)(param_1 + 0x10);
                      plVar15 = *(longlong **)(lVar14 + 0xe18);
                      if (plVar15 == (longlong *)0x0) {
                        plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,1);
                      }
                      else {
                        lVar4 = plVar15[3];
                        *(int *)(lVar14 + 0xeb8) = *(int *)(lVar14 + 0xeb8) + -1;
                        *(longlong *)(lVar14 + 0xe18) = lVar4;
                        *plVar15 = 1;
                      }
                      pcStack_f8 = _PyRuntime_exref;
                      lVar14 = *(longlong *)
                                (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) +
                                0x2e8);
                      lVar4 = plVar15[-1];
                      puVar5 = *(undefined8 **)(lVar14 + 8);
                      *puVar5 = plVar15 + -2;
                      plVar15[-2] = lVar14;
                      plVar15[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
                      *(longlong **)(lVar14 + 8) = plVar15 + -2;
                      uVar12 = _DAT_23eed9838;
                      *plStack_108 = *plStack_108 + 1;
                      plVar15[3] = (longlong)plStack_108;
                      plVar13 = (longlong *)FUN_23e8d7870(param_1,uVar12);
                      *(undefined4 *)(pppppcVar7 + 5) = 0x668;
                      plVar16 = (longlong *)FUN_23a334c60(param_1,plVar9,plVar15,plVar13);
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        (**(code **)(plVar15[1] + 0x30))(plVar15);
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      if (plVar16 == (longlong *)0x0) {
                        uVar12 = *(undefined8 *)(param_1 + 0x60);
                        uVar24 = *(undefined8 *)(param_1 + 0x68);
                        pppppcVar23 = *(code ******)(param_1 + 0x70);
                        uVar21 = 0x668;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        *plVar16 = *plVar16 + -1;
                        if (*plVar16 == 0) {
                          (**(code **)(plVar16[1] + 0x30))(plVar16);
                        }
                        lVar14 = _DAT_23eed9848;
                        *(undefined4 *)(pppppcVar7 + 5) = 0x669;
                        plVar9 = (longlong *)
                                 FUN_23e915840(param_1,plStack_108,_DAT_23eed9840,
                                               *(undefined8 *)(lVar14 + 0x18));
                        if (plVar9 == (longlong *)0x0) {
                          uVar12 = *(undefined8 *)(param_1 + 0x60);
                          uVar24 = *(undefined8 *)(param_1 + 0x68);
                          pppppcVar23 = *(code ******)(param_1 + 0x70);
                          uVar21 = 0x669;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                        else {
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                          }
                          *(undefined4 *)(pppppcVar7 + 5) = 0x66b;
                          pppppppcVar10 =
                               (code *******)FUN_23e91bfe0(param_1,plStack_108,DAT_23ed6ce70);
                          if (pppppppcVar10 != (code *******)0x0) goto LAB_23e77fc73;
                          uVar12 = *(undefined8 *)(param_1 + 0x60);
                          uVar24 = *(undefined8 *)(param_1 + 0x68);
                          pppppcVar23 = *(code ******)(param_1 + 0x70);
                          uVar21 = 0x66b;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_23e77f96e:
    plVar9 = *(longlong **)(param_1 + 0x138);
    auStack_c8._8_8_ = uVar24;
    auStack_c8._0_8_ = uVar12;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
    ppppppcVar18 = DAT_23ed6a4f8;
    appppppcStack_b8[0] = (code ******)pppppcVar23;
    if (pppppcVar23 == (code *****)0x0) {
      if (DAT_23ed6a4f8 == (code ******)0x0) {
        ppppppcVar18 = (code ******)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        ppppppcVar20 = (code ******)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = (code *****)0x1;
        DAT_23ed6a4f8 = ppppppcVar20;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      ppppppcVar18[2] = (code *****)0x0;
      ppppppcVar18[3] = pppppcVar7;
      *pppppcVar7 = (code ****)((longlong)*pppppcVar7 + 1);
      lVar14 = *(longlong *)(pcStack_f8 + 0x1f8);
      *(undefined4 *)((longlong)ppppppcVar18 + 0x24) = uVar21;
      lVar14 = *(longlong *)(lVar14 + 0x10);
      *(undefined4 *)(ppppppcVar18 + 4) = 0xffffffff;
      pppppcVar23 = *(code ******)(lVar14 + 0x2e8);
      pppppcVar11 = ppppppcVar18[-1];
      ppppcVar17 = pppppcVar23[1];
      *ppppcVar17 = (code ***)(ppppppcVar18 + -2);
      ppppppcVar18[-2] = pppppcVar23;
      ppppppcVar18[-1] = (code *****)((ulonglong)((uint)pppppcVar11 & 3) | (ulonglong)ppppcVar17);
      pppppcVar23[1] = (code ****)(ppppppcVar18 + -2);
      if ((appppppcStack_b8[0] != (code ******)0x0) &&
         (*appppppcStack_b8[0] = (code *****)((longlong)*appppppcStack_b8[0] + -1),
         *appppppcStack_b8[0] == (code *****)0x0)) {
        (*(code *)appppppcStack_b8[0][1][6])(appppppcStack_b8[0]);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code ******)0x0) {
        ppppppcVar18 = (code ******)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        ppppppcVar20 = (code ******)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = (code *****)0x1;
        DAT_23ed6a4f8 = ppppppcVar20;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      ppppppcVar18[3] = pppppcVar7;
      *pppppcVar7 = (code ****)((longlong)*pppppcVar7 + 1);
      lVar14 = *(longlong *)(pcStack_f8 + 0x1f8);
      *(undefined4 *)((longlong)ppppppcVar18 + 0x24) = uVar21;
      *(undefined4 *)(ppppppcVar18 + 4) = 0xffffffff;
      pppppcVar11 = *(code ******)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
      pppppcVar3 = ppppppcVar18[-1];
      ppppcVar17 = pppppcVar11[1];
      *ppppcVar17 = (code ***)(ppppppcVar18 + -2);
      ppppppcVar18[-2] = pppppcVar11;
      ppppppcVar18[-1] = (code *****)((ulonglong)((uint)pppppcVar3 & 3) | (ulonglong)ppppcVar17);
      pppppcVar11[1] = (code ****)(ppppppcVar18 + -2);
      ppppppcVar18[2] = pppppcVar23;
      *pppppcVar23 = (code ****)((longlong)*pppppcVar23 + 1);
      if ((appppppcStack_b8[0] != (code ******)0x0) &&
         (*appppppcStack_b8[0] = (code *****)((longlong)*appppppcStack_b8[0] + -1),
         *appppppcStack_b8[0] == (code *****)0x0)) {
        (*(code *)appppppcStack_b8[0][1][6])();
      }
    }
    appppppcStack_b8[0] = ppppppcVar18;
    if (((code *)auStack_c8._0_8_ != _Py_NoneStruct_exref) &&
       ((code *)auStack_c8._0_8_ != (code *)0x0)) {
      FUN_23e91b1b0(param_1,auStack_c8,auStack_c8 + 8,appppppcStack_b8);
    }
    plVar15 = *(longlong **)(auStack_c8._8_8_ + 0x28);
    if (appppppcStack_b8[0] == (code ******)_Py_NoneStruct_exref) {
      ppppppcVar18 = (code ******)0x0;
    }
    else {
      ppppppcVar18 = appppppcStack_b8[0];
      if (appppppcStack_b8[0] != (code ******)0x0) {
        *appppppcStack_b8[0] = (code *****)((longlong)*appppppcStack_b8[0] + 1);
      }
    }
    *(code *******)(auStack_c8._8_8_ + 0x28) = ppppppcVar18;
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))();
    }
    plVar15 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = auStack_c8._8_8_;
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))();
    }
    *(longlong *)auStack_c8._0_8_ = *(longlong *)auStack_c8._0_8_ + -1;
    if (*(longlong *)auStack_c8._0_8_ == 0) {
      (**(code **)(*(longlong *)(auStack_c8._0_8_ + 8) + 0x30))();
    }
    if ((appppppcStack_b8[0] != (code ******)0x0) &&
       (*appppppcStack_b8[0] = (code *****)((longlong)*appppppcStack_b8[0] + -1),
       *appppppcStack_b8[0] == (code *****)0x0)) {
      (*(code *)appppppcStack_b8[0][1][6])();
    }
    pppppppcVar10 = *(code ********)(param_1 + 0x138);
    appppppcStack_b8[0] = (code ******)0x0;
    auStack_c8 = (undefined1  [16])0x0;
    ppppppcVar18 = *(code *******)PyExc_Exception_exref;
    ppppppcVar20 = pppppppcVar10[1];
    if ((*(uint *)(ppppppcVar18[1] + 0x15) & 0x4000000) == 0) {
      if (((int)*(uint *)(ppppppcVar18[1] + 0x15) < 0) &&
         (((byte)*(code *)((longlong)ppppppcVar18 + 0xab) & 0x40) != 0)) {
        ppppppcVar6 = (code ******)ppppppcVar20[1];
        if ((*(uint *)(ppppppcVar6 + 0x15) & 0x40000000) == 0) {
          if ((-1 < (int)*(uint *)(ppppppcVar6 + 0x15)) ||
             (((byte)*(code *)((longlong)ppppppcVar20 + 0xab) & 0x40) == 0)) goto LAB_23e78089a;
        }
        else {
          ppppppcVar20 = ppppppcVar6;
          if (-1 < *(int *)(ppppppcVar6[1] + 0x15)) {
LAB_23e78089a:
            if (ppppppcVar18 != ppppppcVar20) goto LAB_23e77fbe5;
            goto LAB_23e77fe14;
          }
        }
        pppppcVar23 = ppppppcVar20[0x2b];
        if (pppppcVar23 == (code *****)0x0) {
          do {
            if (ppppppcVar18 == ppppppcVar20) goto LAB_23e77fe14;
            ppppppcVar20 = (code ******)ppppppcVar20[0x20];
          } while (ppppppcVar20 != (code ******)0x0);
          if (ppppppcVar18 == (code ******)PyBaseObject_Type_exref) goto LAB_23e77fe14;
        }
        else if (0 < (longlong)pppppcVar23[2]) {
          ppppcVar17 = (code ****)0x0;
          do {
            if (ppppppcVar18 == (code ******)pppppcVar23[(longlong)ppppcVar17 + 3])
            goto LAB_23e77fe14;
            ppppcVar17 = (code ****)((longlong)ppppcVar17 + 1);
          } while (pppppcVar23[2] != ppppcVar17);
        }
        goto LAB_23e77fbe5;
      }
LAB_23e77fd88:
      plVar15 = *(longlong **)PyExc_TypeError_exref;
      uVar12 = PyUnicode_FromString
                         ("catching classes that do not inherit from BaseException is not allowed");
      plVar13 = *(longlong **)(param_1 + 0x60);
      plVar16 = *(longlong **)(param_1 + 0x68);
      plVar19 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar15;
      *plVar15 = *plVar15 + 1;
      *(undefined8 *)(param_1 + 0x68) = uVar12;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
        (**(code **)(plVar13[1] + 0x30))();
      }
      if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      if ((plVar19 == (longlong *)0x0) || (*plVar19 = *plVar19 + -1, *plVar19 != 0)) {
LAB_23e78007d:
        pppppppcVar10 = *(code ********)(param_1 + 0x138);
      }
      else {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
        pppppppcVar10 = *(code ********)(param_1 + 0x138);
      }
LAB_23e77fe14:
      *pppppppcVar10 = (code ******)((longlong)*pppppppcVar10 + 1);
      plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8b40);
      plVar15 = _DAT_23eed9850;
      if (plVar13 == (longlong *)0x0) {
LAB_23e780288:
        pppppppcStack_e8 = *(code ********)(param_1 + 0x68);
        ppppppcVar18 = *(code *******)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        unaff_R14 = *(code *******)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        lVar14 = *(longlong *)(param_1 + 0x10);
        plVar16 = *(longlong **)(lVar14 + 0xe20);
        if (plVar16 == (longlong *)0x0) {
          plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar4 = plVar16[3];
          *(int *)(lVar14 + 0xebc) = *(int *)(lVar14 + 0xebc) + -1;
          *(longlong *)(lVar14 + 0xe20) = lVar4;
          *plVar16 = 1;
        }
        plVar16[4] = 0;
        lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_f8 + 0x1f8) + 0x10) + 0x2e8);
        lVar4 = plVar16[-1];
        puVar5 = *(undefined8 **)(lVar14 + 8);
        *puVar5 = plVar16 + -2;
        plVar16[-2] = lVar14;
        plVar16[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar5;
        *(longlong **)(lVar14 + 8) = plVar16 + -2;
        *plVar15 = *plVar15 + 1;
        plVar16[3] = (longlong)plVar15;
        plVar15 = DAT_23ed6cd28;
        unaff_R14 = (code ******)&DAT_23ed6a4c0;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plVar19 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar19 == (longlong *)0x0) goto LAB_23e780a30;
          *plVar19 = *plVar19 + 1;
          DAT_23ed6a4c0 = plVar19;
        }
        plStack_80 = plVar15;
        pppppppcStack_88 = pppppppcVar10;
        lVar14 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pppppppcStack_e8);
        if (lVar14 == 0) {
          pppppppcStack_e8 = *(code ********)(param_1 + 0x68);
          unaff_R14 = *(code *******)(param_1 + 0x60);
          ppppppcVar18 = *(code *******)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
        }
        else {
          plVar16[4] = lVar14;
          plVar15 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (plVar15 != (longlong *)0x0) {
            *(undefined4 *)(pppppcVar7 + 5) = 0x66d;
            plVar16 = (longlong *)FUN_23e914090(param_1,plVar13,plVar15);
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if (plVar16 != (longlong *)0x0) {
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
              *pppppppcVar10 = (code ******)((longlong)*pppppppcVar10 + -1);
              if (*pppppppcVar10 == (code ******)0x0) {
                (*(code *)pppppppcVar10[1][6])(pppppppcVar10);
              }
              plVar15 = *(longlong **)(param_1 + 0x138);
              *(longlong **)(param_1 + 0x138) = plVar9;
              pppppppcVar10 = (code *******)_Py_NoneStruct_exref;
              if ((plVar15 != (longlong *)0x0) &&
                 (*plVar15 = *plVar15 + -1, pppppppcVar10 = (code *******)_Py_NoneStruct_exref,
                 *plVar15 == 0)) {
                (**(code **)(plVar15[1] + 0x30))();
                pppppppcVar10 = (code *******)_Py_NoneStruct_exref;
              }
LAB_23e77fc73:
              lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar9 = *(longlong **)(lVar14 + 0x28);
              plVar15 = (longlong *)plVar9[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
              *(undefined4 *)(plVar9 + 8) = 0xffffffff;
              if (plVar15 != (longlong *)0x0) {
                plVar9[2] = 0;
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))();
                }
              }
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              plVar9[0xf] = 0;
              if ((unaff_R12 != (longlong *)0x0) && (*unaff_R12 = *unaff_R12 + -1, *unaff_R12 == 0))
              {
                (**(code **)(unaff_R12[1] + 0x30))(unaff_R12);
              }
              if ((pppppppcVar22 != (code *******)0x0) &&
                 (*pppppppcVar22 = (code ******)((longlong)*pppppppcVar22 + -1),
                 *pppppppcVar22 == (code ******)0x0)) {
                (*(code *)pppppppcVar22[1][6])(pppppppcVar22);
              }
              if ((unaff_RBP != (longlong *)0x0) && (*unaff_RBP = *unaff_RBP + -1, *unaff_RBP == 0))
              {
                (**(code **)(unaff_RBP[1] + 0x30))(unaff_RBP);
              }
              if ((plStack_100 != (longlong *)0x0) &&
                 (lVar14 = *plStack_100, *plStack_100 = lVar14 + -1, lVar14 + -1 == 0)) {
                (**(code **)(plStack_100[1] + 0x30))(plStack_100);
              }
              if ((plStack_108 != (longlong *)0x0) &&
                 (lVar14 = *plStack_108, *plStack_108 = lVar14 + -1, lVar14 + -1 == 0)) {
                (**(code **)(plStack_108[1] + 0x30))(plStack_108);
              }
              *plVar1 = *plVar1 + -1;
              if (*plVar1 != 0) {
                return pppppppcVar10;
              }
              (**(code **)(plVar1[1] + 0x30))(plVar1);
              return pppppppcVar10;
            }
            goto LAB_23e780288;
          }
          pppppppcStack_e8 = *(code ********)(param_1 + 0x68);
          unaff_R14 = *(code *******)(param_1 + 0x60);
          ppppppcVar18 = *(code *******)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
        }
      }
      *pppppppcVar10 = (code ******)((longlong)*pppppppcVar10 + -1);
      if (*pppppppcVar10 == (code ******)0x0) {
        (*(code *)pppppppcVar10[1][6])(pppppppcVar10);
      }
      pppppppcVar10 = *(code ********)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar9;
      if ((pppppppcVar10 != (code *******)0x0) &&
         (*pppppppcVar10 = (code ******)((longlong)*pppppppcVar10 + -1),
         *pppppppcVar10 == (code ******)0x0)) {
        iVar8 = 0x66d;
        goto LAB_23e7802e4;
      }
      iVar8 = 0x66d;
      if (ppppppcVar18 == (code ******)0x0) goto LAB_23e780616;
      ppppppcVar20 = ppppppcVar18;
      if (pppppcVar7 == ppppppcVar18[3]) goto LAB_23e7803b0;
      iVar8 = 0x66d;
LAB_23e780314:
      ppppppcVar20 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code ******)0x0) {
        ppppppcVar20 = (code ******)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        ppppppcVar6 = (code ******)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = (code *****)0x1;
        DAT_23ed6a4f8 = ppppppcVar6;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      ppppppcVar20[3] = pppppcVar7;
      *pppppcVar7 = (code ****)((longlong)*pppppcVar7 + 1);
      *(int *)((longlong)ppppppcVar20 + 0x24) = iVar8;
      lVar14 = *(longlong *)(pcStack_f8 + 0x1f8);
      *(undefined4 *)(ppppppcVar20 + 4) = 0xffffffff;
      pppppcVar23 = *(code ******)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
      pppppcVar11 = ppppppcVar20[-1];
      ppppcVar17 = pppppcVar23[1];
      *ppppcVar17 = (code ***)(ppppppcVar20 + -2);
      ppppppcVar20[-2] = pppppcVar23;
      ppppppcVar20[-1] = (code *****)((ulonglong)((uint)pppppcVar11 & 3) | (ulonglong)ppppcVar17);
      pppppcVar11 = *ppppppcVar18;
      pppppcVar23[1] = (code ****)(ppppppcVar20 + -2);
      ppppppcVar20[2] = (code *****)ppppppcVar18;
      if (pppppcVar11 == (code *****)0x0) {
        (*(code *)ppppppcVar18[1][6])(ppppppcVar18);
      }
      goto LAB_23e7803b0;
    }
    pppppcVar23 = ppppppcVar18[2];
    if (0 < (longlong)pppppcVar23) {
      pppppcVar11 = (code *****)0x0;
      do {
        if ((-1 < *(int *)(ppppppcVar18[(longlong)pppppcVar11 + 3][1] + 0x15)) ||
           ((*(byte *)((longlong)ppppppcVar18[(longlong)pppppcVar11 + 3] + 0xab) & 0x40) == 0))
        goto LAB_23e77fd88;
        pppppcVar11 = (code *****)((longlong)pppppcVar11 + 1);
      } while (pppppcVar23 != pppppcVar11);
      pppppcVar11 = (code *****)0x0;
      do {
        iVar8 = FUN_23a35ebd0(param_1,ppppppcVar20,ppppppcVar18[(longlong)pppppcVar11 + 3]);
        if (iVar8 != 0) goto LAB_23e78007d;
        pppppcVar11 = (code *****)((longlong)pppppcVar11 + 1);
      } while (pppppcVar23 != pppppcVar11);
      pppppppcVar10 = *(code ********)(param_1 + 0x138);
    }
LAB_23e77fbe5:
    if ((pppppppcVar10 == (code *******)0x0) ||
       (pppppppcVar10 == (code *******)_Py_NoneStruct_exref)) {
      unaff_R14 = *(code *******)PyExc_RuntimeError_exref;
      pppppppcStack_e8 = (code *******)PyUnicode_FromString("No active exception to reraise");
      pppppppcVar10 = *(code ********)(param_1 + 0x138);
      iVar8 = 0x65b;
      *unaff_R14 = (code *****)((longlong)*unaff_R14 + 1);
      *(longlong **)(param_1 + 0x138) = plVar9;
      if ((pppppppcVar10 != (code *******)0x0) &&
         (*pppppppcVar10 = (code ******)((longlong)*pppppppcVar10 + -1),
         *pppppppcVar10 == (code ******)0x0)) {
        ppppppcVar18 = (code ******)0x0;
LAB_23e7802e4:
        (*(code *)pppppppcVar10[1][6])(pppppppcVar10);
        if (ppppppcVar18 != (code ******)0x0) {
LAB_23e780300:
          ppppppcVar20 = ppppppcVar18;
          if (pppppcVar7 == ppppppcVar18[3]) goto LAB_23e7803b0;
          if (iVar8 == 0) goto LAB_23e780311;
          goto LAB_23e780314;
        }
        if (iVar8 == 0) goto LAB_23e78060e;
      }
    }
    else {
      unaff_R14 = pppppppcVar10[1];
      ppppppcVar18 = pppppppcVar10[5];
      *pppppppcVar10 = (code ******)((longlong)*pppppppcVar10 + 1);
      *unaff_R14 = (code *****)((longlong)*unaff_R14 + 1);
      pppppppcStack_e8 = pppppppcVar10;
      if (ppppppcVar18 != (code ******)0x0) {
        *ppppppcVar18 = (code *****)((longlong)*ppppppcVar18 + 1);
        if (pppppcVar7 == ppppppcVar18[3]) {
          *(undefined4 *)(pppppcVar7 + 5) = *(undefined4 *)((longlong)ppppppcVar18 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar9;
        *pppppppcVar10 = (code ******)((longlong)*pppppppcVar10 + -1);
        if (*pppppppcVar10 == (code ******)0x0) {
          (*(code *)unaff_R14[6])(pppppppcVar10);
          iVar8 = 0;
          goto LAB_23e780300;
        }
        ppppppcVar20 = ppppppcVar18;
        if (ppppppcVar18[3] == pppppcVar7) goto LAB_23e7803b0;
LAB_23e780311:
        iVar8 = *(int *)(pppppcVar7 + 5);
        goto LAB_23e780314;
      }
      *(longlong **)(param_1 + 0x138) = plVar9;
      *pppppppcVar10 = (code ******)((longlong)*pppppppcVar10 + -1);
      if (*pppppppcVar10 == (code ******)0x0) {
        iVar8 = 0;
        goto LAB_23e7802e4;
      }
LAB_23e78060e:
      iVar8 = *(int *)(pppppcVar7 + 5);
    }
LAB_23e780616:
    ppppppcVar20 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code ******)0x0) goto LAB_23e780a43;
    ppppppcVar18 = (code ******)*DAT_23ed6a4f8;
    *DAT_23ed6a4f8 = (code *****)0x1;
    DAT_23ed6a4f8 = ppppppcVar18;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  ppppppcVar20[2] = (code *****)0x0;
  ppppppcVar20[3] = pppppcVar7;
  *pppppcVar7 = (code ****)((longlong)*pppppcVar7 + 1);
  *(int *)((longlong)ppppppcVar20 + 0x24) = iVar8;
  lVar14 = *(longlong *)(pcStack_f8 + 0x1f8);
  *(undefined4 *)(ppppppcVar20 + 4) = 0xffffffff;
  pppppcVar23 = *(code ******)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
  pppppcVar11 = ppppppcVar20[-1];
  ppppcVar17 = pppppcVar23[1];
  *ppppcVar17 = (code ***)(ppppppcVar20 + -2);
  ppppppcVar20[-2] = pppppcVar23;
  ppppppcVar20[-1] = (code *****)((ulonglong)((uint)pppppcVar11 & 3) | (ulonglong)ppppcVar17);
  pppppcVar23[1] = (code ****)(ppppppcVar20 + -2);
LAB_23e7803b0:
  FUN_23e8bba40(pppppcVar7,"ooooooo",plVar1,unaff_R12,pppppppcVar22,unaff_RBP,plStack_100,
                plStack_108,0);
  if (_DAT_23eedad10 == pppppcVar7) {
    *pppppcVar7 = (code ****)((longlong)*pppppcVar7 + -1);
    if (*pppppcVar7 == (code ****)0x0) {
      (*(code *)pppppcVar7[1][6])(pppppcVar7);
    }
    _DAT_23eedad10 = (code *****)0x0;
  }
  lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar14 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
  plVar15 = (longlong *)plVar9[2];
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar15 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  if ((unaff_R12 != (longlong *)0x0) && (*unaff_R12 = *unaff_R12 + -1, *unaff_R12 == 0)) {
    (**(code **)(unaff_R12[1] + 0x30))(unaff_R12);
  }
  if ((pppppppcVar22 != (code *******)0x0) &&
     (*pppppppcVar22 = (code ******)((longlong)*pppppppcVar22 + -1),
     *pppppppcVar22 == (code ******)0x0)) {
    (*(code *)pppppppcVar22[1][6])(pppppppcVar22);
  }
  if ((unaff_RBP != (longlong *)0x0) && (*unaff_RBP = *unaff_RBP + -1, *unaff_RBP == 0)) {
    (**(code **)(unaff_RBP[1] + 0x30))(unaff_RBP);
  }
  if ((plStack_100 != (longlong *)0x0) &&
     (lVar14 = *plStack_100, *plStack_100 = lVar14 + -1, lVar14 + -1 == 0)) {
    (**(code **)(plStack_100[1] + 0x30))(plStack_100);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar14 = *plStack_108, *plStack_108 = lVar14 + -1, lVar14 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,unaff_R14,pppppppcStack_e8,ppppppcVar20);
  return (code *******)0x0;
}
