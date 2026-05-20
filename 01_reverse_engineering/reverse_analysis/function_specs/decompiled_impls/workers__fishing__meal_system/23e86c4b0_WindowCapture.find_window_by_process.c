/* ===== 23e86c4b0 workers.fishing.meal_system:81 ===== */
/* ghidra_name=FUN_23e86c4b0 entry=23e86c4b0 size=12397 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e86c4b0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  undefined8 uVar18;
  code *pcVar19;
  code *pcVar20;
  longlong lVar21;
  undefined4 uVar22;
  undefined1 auVar23 [8];
  longlong *plStack_140;
  code *pcStack_138;
  longlong *plStack_130;
  longlong *plStack_128;
  longlong *plStack_120;
  code *pcStack_118;
  longlong *plStack_110;
  longlong *plStack_108;
  longlong *plStack_100;
  code *pcStack_f8;
  code *pcStack_e8;
  longlong *plStack_c8;
  undefined8 uStack_c0;
  undefined1 auStack_b8 [8];
  code *pcStack_b0;
  code *pcStack_a8;
  undefined1 auStack_98 [16];
  code *pcStack_88;
  undefined8 uStack_80;
  longlong *plStack_78;
  
  plVar9 = _DAT_23eeded40;
  plVar2 = (longlong *)*param_3;
  pcStack_a8 = (code *)0x0;
  auStack_b8 = (undefined1  [8])0x0;
  pcStack_b0 = (code *)0x0;
  if (_DAT_23eeded40 == (longlong *)0x0) {
LAB_23e86c515:
    _DAT_23eeded40 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeded38,DAT_23eed7940,0x78);
  }
  else {
    lVar10 = *_DAT_23eeded40;
    if (1 < lVar10) {
      *_DAT_23eeded40 = lVar10 + -1;
      goto LAB_23e86c515;
    }
    if (_DAT_23eeded40[2] != 0) {
      *_DAT_23eeded40 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e86c515;
    }
  }
  plVar3 = _DAT_23eeded40;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeded40 + 9;
  lVar21 = *(longlong *)(lVar10 + 8);
  _DAT_23eeded40[0xf] = lVar21;
  *(longlong **)(lVar10 + 8) = plVar9;
  if ((lVar21 != 0) &&
     (((*(char *)(lVar21 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar21 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar21 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar21 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar21 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed70a8);
  if (plVar9 == (longlong *)0x0) {
LAB_23e86d700:
    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_b0 = *(code **)(param_1 + 0x68);
    pcStack_a8 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_a8 != (code *)0x0) {
      plVar9 = *(longlong **)(pcStack_a8 + 0x18);
      goto joined_r0x00023e86d737;
    }
  }
  else {
    iVar7 = FUN_23a35f020();
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
    if (iVar7 == -1) {
LAB_23e86e100:
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_b0 = *(code **)(param_1 + 0x68);
      pcStack_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcStack_a8 != (code *)0x0) {
        plVar9 = *(longlong **)(pcStack_a8 + 0x18);
        goto joined_r0x00023e86d737;
      }
    }
    else {
      if (iVar7 == 0) {
LAB_23e86c5df:
        pcVar17 = _Py_NoneStruct_exref;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        pcStack_138 = (code *)0x0;
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        plStack_128 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        pcStack_118 = (code *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_f8 = (code *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
LAB_23e86c66a:
        lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar3 = *(longlong **)(lVar10 + 0x28);
        plVar13 = (longlong *)plVar3[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
        *(undefined4 *)(plVar3 + 8) = 0xffffffff;
        if (plVar13 != (longlong *)0x0) {
          plVar3[2] = 0;
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))();
          }
        }
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))(plVar3);
        }
        plVar3[0xf] = 0;
        if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar11 != (longlong *)0x0) {
LAB_23e86c6cc:
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
LAB_23e86d670:
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
        }
        if (plVar12 != (longlong *)0x0) {
LAB_23e86c6dc:
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
        }
        if ((plStack_140 != (longlong *)0x0) &&
           (lVar10 = *plStack_140, *plStack_140 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_140[1] + 0x30))(plStack_140);
        }
        if ((plStack_100 != (longlong *)0x0) &&
           (lVar10 = *plStack_100, *plStack_100 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_100[1] + 0x30))(plStack_100);
        }
        if ((pcStack_f8 != (code *)0x0) &&
           (lVar10 = *(longlong *)pcStack_f8, *(longlong *)pcStack_f8 = lVar10 + -1,
           lVar10 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcStack_f8 + 8) + 0x30))(pcStack_f8);
        }
        if ((plStack_108 != (longlong *)0x0) &&
           (lVar10 = *plStack_108, *plStack_108 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_108[1] + 0x30))(plStack_108);
        }
        if ((pcStack_118 != (code *)0x0) &&
           (lVar10 = *(longlong *)pcStack_118, *(longlong *)pcStack_118 = lVar10 + -1,
           lVar10 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcStack_118 + 8) + 0x30))(pcStack_118);
        }
        if ((plStack_110 != (longlong *)0x0) &&
           (lVar10 = *plStack_110, *plStack_110 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_110[1] + 0x30))(plStack_110);
        }
        if ((plStack_120 != (longlong *)0x0) &&
           (lVar10 = *plStack_120, *plStack_120 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_120[1] + 0x30))(plStack_120);
        }
        if ((plStack_130 != (longlong *)0x0) &&
           (lVar10 = *plStack_130, *plStack_130 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_130[1] + 0x30))(plStack_130);
        }
        if ((plStack_128 != (longlong *)0x0) &&
           (lVar10 = *plStack_128, *plStack_128 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_128[1] + 0x30))(plStack_128);
        }
        if ((pcStack_138 != (code *)0x0) &&
           (lVar10 = *(longlong *)pcStack_138, *(longlong *)pcStack_138 = lVar10 + -1,
           lVar10 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcStack_138 + 8) + 0x30))(pcStack_138);
        }
        *plVar2 = *plVar2 + -1;
        if (*plVar2 != 0) {
          return pcVar17;
        }
        (**(code **)(plVar2[1] + 0x30))(plVar2);
        return pcVar17;
      }
      lVar10 = FUN_23e8de4a0();
      if (lVar10 == 0) {
        FUN_23e915740(param_1,auStack_b8,uRam000000023eed70c0);
        if (pcStack_a8 != (code *)0x0) {
          plVar9 = *(longlong **)(pcStack_a8 + 0x18);
          goto joined_r0x00023e86d737;
        }
      }
      else {
        plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,uRam000000023eed7118);
        if (plVar9 == (longlong *)0x0) goto LAB_23e86d700;
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed70a8);
        if (plVar11 == (longlong *)0x0) {
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          pcStack_a8 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
            if (pcStack_a8 != (code *)0x0) {
              plVar9 = *(longlong **)(pcStack_a8 + 0x18);
joined_r0x00023e86d737:
              if (plVar3 == plVar9) {
                pcStack_138 = (code *)0x0;
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                pcStack_118 = (code *)0x0;
                plStack_108 = (longlong *)0x0;
                pcStack_f8 = (code *)0x0;
                plStack_100 = (longlong *)0x0;
                plStack_140 = (longlong *)0x0;
                pcVar20 = pcStack_a8;
              }
              else {
                plVar9 = (longlong *)0x0;
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                pcStack_f8 = (code *)0x0;
                plStack_100 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                pcStack_118 = (code *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                pcStack_138 = (code *)0x0;
                plStack_140 = (longlong *)0x0;
                iVar7 = 0x53;
                pcStack_e8 = _PyRuntime_exref;
LAB_23e86d7dd:
                pcVar17 = pcStack_a8;
                pcVar20 = DAT_23ed6a4f8;
                if (DAT_23ed6a4f8 == (code *)0x0) {
                  pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                }
                else {
                  pcVar19 = *(code **)DAT_23ed6a4f8;
                  *(undefined8 *)DAT_23ed6a4f8 = 1;
                  DAT_23ed6a4f8 = pcVar19;
                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                }
                *(longlong **)(pcVar20 + 0x18) = plVar3;
                *plVar3 = *plVar3 + 1;
                lVar10 = *(longlong *)(pcStack_e8 + 0x1f8);
                *(int *)(pcVar20 + 0x24) = iVar7;
                *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
                lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
                lVar21 = *(longlong *)(pcVar20 + -8);
                plVar13 = *(longlong **)(lVar10 + 8);
                *plVar13 = (longlong)(pcVar20 + -0x10);
                *(longlong *)(pcVar20 + -0x10) = lVar10;
                *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)plVar13;
                *(code **)(lVar10 + 8) = pcVar20 + -0x10;
                *(code **)(pcVar20 + 0x10) = pcVar17;
                *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
                if ((pcStack_a8 != (code *)0x0) &&
                   (*(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + -1,
                   *(longlong *)pcStack_a8 == 0)) {
                  (**(code **)(*(longlong *)(pcStack_a8 + 8) + 0x30))();
                }
              }
              goto LAB_23e86d888;
            }
          }
          else if (pcStack_a8 != (code *)0x0) {
            plVar9 = *(longlong **)(pcStack_a8 + 0x18);
            goto joined_r0x00023e86d737;
          }
        }
        else {
          *(undefined4 *)(plVar3 + 5) = 0x53;
          plVar12 = (longlong *)FUN_23e914090(param_1,plVar9,plVar11);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))();
          }
          if (plVar12 != (longlong *)0x0) {
            uVar8 = FUN_23a35f020();
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))();
            }
            if (uVar8 != 0xffffffff) {
              if ((uVar8 & 1) == 0) goto LAB_23e86c5df;
              lVar10 = FUN_23e8de4a0();
              if (lVar10 == 0) {
                FUN_23e915740(param_1,auStack_b8,uRam000000023eed70c0);
                pcVar17 = pcStack_a8;
                auVar23 = auStack_b8;
                pcVar20 = pcStack_b0;
              }
              else {
                plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,uRam000000023eed7128);
                if (plVar9 != (longlong *)0x0) {
                  plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed70a8);
                  if (plVar11 == (longlong *)0x0) {
                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_b0 = *(code **)(param_1 + 0x68);
                    pcStack_a8 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar9 = *plVar9 + -1;
                    pcVar17 = pcStack_a8;
                    auVar23 = auStack_b8;
                    pcVar20 = pcStack_b0;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                      pcVar17 = pcStack_a8;
                      auVar23 = auStack_b8;
                      pcVar20 = pcStack_b0;
                    }
                    goto LAB_23e86dc01;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x57;
                  plVar12 = (longlong *)FUN_23e914090(param_1,plVar9,plVar11);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar12 != (longlong *)0x0) {
                    plVar13 = (longlong *)FUN_23a388310(plVar12);
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    if (plVar13 != (longlong *)0x0) {
                      pcVar20 = (code *)auStack_b8;
                      plVar9 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                      if ((plVar9 == (longlong *)0x0) &&
                         (plVar9 = (longlong *)FUN_23a3c1b70(param_1,pcVar20,0,4),
                         plVar9 == (longlong *)0x0)) {
                        plStack_140 = (longlong *)0x0;
                        plVar12 = (longlong *)0x0;
                        plVar11 = (longlong *)0x0;
                        goto LAB_23e86e7ef;
                      }
                      plVar11 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                      if (plVar11 == (longlong *)0x0) {
                        plVar12 = (longlong *)0x0;
                        plVar11 = (longlong *)FUN_23a3c1b70(param_1,pcVar20,1,4);
                        plStack_140 = (longlong *)0x0;
                        if (plVar11 == (longlong *)0x0) goto LAB_23e86e7ef;
                      }
                      plVar12 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                      if (plVar12 == (longlong *)0x0) goto LAB_23e86ec83;
                      goto LAB_23e86caa1;
                    }
                  }
                }
                pcVar17 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                auVar23 = *(undefined1 (*) [8])(param_1 + 0x60);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar20 = *(code **)(param_1 + 0x68);
              }
LAB_23e86dc01:
              do {
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                pcStack_138 = (code *)0x0;
                uVar22 = 0x57;
                plStack_128 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                pcStack_118 = (code *)0x0;
                plStack_108 = (longlong *)0x0;
                pcStack_f8 = (code *)0x0;
                plStack_100 = (longlong *)0x0;
                plStack_140 = (longlong *)0x0;
                pcStack_a8 = pcVar17;
                auStack_b8 = auVar23;
                pcStack_b0 = pcVar20;
LAB_23e86dc95:
                pcVar17 = pcStack_a8;
                auStack_98._8_8_ = pcStack_b0;
                auStack_98._0_8_ = auStack_b8;
                pcStack_a8 = (code *)0x0;
                auStack_b8 = (undefined1  [8])0x0;
                pcStack_b0 = (code *)0x0;
                pcStack_88 = pcVar17;
                plVar14 = *(longlong **)(param_1 + 0x138);
                if (plVar14 != (longlong *)0x0) {
                  *plVar14 = *plVar14 + 1;
                }
                pcVar19 = DAT_23ed6a4f8;
                if (pcVar17 == (code *)0x0) {
                  if (DAT_23ed6a4f8 == (code *)0x0) {
                    pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                  }
                  else {
                    pcVar17 = *(code **)DAT_23ed6a4f8;
                    *(undefined8 *)DAT_23ed6a4f8 = 1;
                    DAT_23ed6a4f8 = pcVar17;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                  }
                  pcStack_e8 = _PyRuntime_exref;
                  *(longlong *)(pcVar19 + 0x10) = 0;
                  *(longlong **)(pcVar19 + 0x18) = plVar3;
                  *plVar3 = *plVar3 + 1;
                  lVar10 = *(longlong *)(pcStack_e8 + 0x1f8);
                  *(undefined4 *)(pcVar19 + 0x24) = uVar22;
                  lVar10 = *(longlong *)(lVar10 + 0x10);
                  *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
                  lVar10 = *(longlong *)(lVar10 + 0x2e8);
                  lVar21 = *(longlong *)(pcVar19 + -8);
                  plVar13 = *(longlong **)(lVar10 + 8);
                  *plVar13 = (longlong)(pcVar19 + -0x10);
                  *(longlong *)(pcVar19 + -0x10) = lVar10;
                  *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)plVar13;
                  *(code **)(lVar10 + 8) = pcVar19 + -0x10;
                  if ((pcStack_88 != (code *)0x0) &&
                     (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1,
                     *(longlong *)pcStack_88 == 0)) {
                    (**(code **)(*(longlong *)(pcStack_88 + 8) + 0x30))(pcStack_88);
                  }
                }
                else {
                  if (DAT_23ed6a4f8 == (code *)0x0) {
                    pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                  }
                  else {
                    pcVar20 = *(code **)DAT_23ed6a4f8;
                    *(undefined8 *)DAT_23ed6a4f8 = 1;
                    DAT_23ed6a4f8 = pcVar20;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                  }
                  pcStack_e8 = _PyRuntime_exref;
                  *(longlong **)(pcVar19 + 0x18) = plVar3;
                  *plVar3 = *plVar3 + 1;
                  lVar10 = *(longlong *)(pcStack_e8 + 0x1f8);
                  *(undefined4 *)(pcVar19 + 0x24) = uVar22;
                  lVar10 = *(longlong *)(lVar10 + 0x10);
                  *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
                  lVar10 = *(longlong *)(lVar10 + 0x2e8);
                  lVar21 = *(longlong *)(pcVar19 + -8);
                  plVar13 = *(longlong **)(lVar10 + 8);
                  *plVar13 = (longlong)(pcVar19 + -0x10);
                  *(longlong *)(pcVar19 + -0x10) = lVar10;
                  *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)plVar13;
                  *(code **)(lVar10 + 8) = pcVar19 + -0x10;
                  *(code **)(pcVar19 + 0x10) = pcVar17;
                  *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
                  if ((pcStack_88 != (code *)0x0) &&
                     (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1,
                     *(longlong *)pcStack_88 == 0)) {
                    (**(code **)(*(longlong *)(pcStack_88 + 8) + 0x30))();
                  }
                }
                pcVar20 = _Py_NoneStruct_exref;
                pcStack_88 = pcVar19;
                if (((code *)auStack_98._0_8_ != (code *)0x0) &&
                   ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref)) {
                  FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,&pcStack_88);
                }
                plVar13 = *(longlong **)(auStack_98._8_8_ + 0x28);
                if (pcStack_88 == pcVar20) {
                  pcVar17 = (code *)0x0;
                }
                else {
                  pcVar17 = pcStack_88;
                  if (pcStack_88 != (code *)0x0) {
                    *(longlong *)pcStack_88 = *(longlong *)pcStack_88 + 1;
                  }
                }
                *(code **)(auStack_98._8_8_ + 0x28) = pcVar17;
                if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                  (**(code **)(plVar13[1] + 0x30))();
                }
                plVar13 = *(longlong **)(param_1 + 0x138);
                *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
                if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                  (**(code **)(plVar13[1] + 0x30))();
                }
                *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
                if (*(longlong *)auStack_98._0_8_ == 0) {
                  (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
                }
                if ((pcStack_88 != (code *)0x0) &&
                   (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1,
                   *(longlong *)pcStack_88 == 0)) {
                  (**(code **)(*(longlong *)(pcStack_88 + 8) + 0x30))();
                }
                pcStack_88 = (code *)0x0;
                auStack_98 = (undefined1  [16])0x0;
                iVar7 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                      *(undefined8 *)PyExc_Exception_exref);
                if (iVar7 == 0) {
                  pcVar17 = *(code **)(param_1 + 0x138);
                  pcStack_b0 = pcVar17;
                  if ((pcVar17 == pcVar20) || (pcVar17 == (code *)0x0)) {
                    pcVar20 = (code *)0x0;
                    auVar23 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
                    pcVar17 = (code *)PyUnicode_FromString("No active exception to reraise");
                    pcVar19 = *(code **)(param_1 + 0x138);
                    iVar7 = 0x56;
                    *(longlong *)auVar23 = *(longlong *)auVar23 + 1;
                    goto LAB_23e86e5f0;
                  }
                  auVar23 = *(undefined1 (*) [8])(pcVar17 + 8);
                  pcVar20 = *(code **)(pcVar17 + 0x28);
                  *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
                  *(longlong *)auVar23 = *(longlong *)auVar23 + 1;
                  iVar7 = 0;
                  pcVar19 = pcVar17;
                  if (pcVar20 == (code *)0x0) {
                    *(longlong **)(param_1 + 0x138) = plVar14;
                  }
                  else {
                    *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                    if (*(longlong **)(pcVar20 + 0x18) == plVar3) {
                      *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar20 + 0x24);
                    }
                    *(longlong **)(param_1 + 0x138) = plVar14;
                  }
LAB_23e86e460:
                  pcStack_a8 = (code *)0x0;
                  _auStack_b8 = (undefined1  [16])0x0;
                  *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
                  if (*(longlong *)pcVar19 == 0) {
                    (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
                  }
                  auStack_b8 = auVar23;
                  pcStack_b0 = pcVar17;
                  if (pcVar20 == (code *)0x0) {
                    pcStack_a8 = (code *)0x0;
                    if (iVar7 == 0) {
                      iVar7 = (int)plVar3[5];
                    }
                    goto LAB_23e86e26b;
                  }
LAB_23e86e4bf:
                  if (*(longlong **)(pcVar20 + 0x18) == plVar3) goto LAB_23e86d888;
                  pcStack_a8 = pcVar20;
                  if (iVar7 == 0) {
                    iVar7 = (int)plVar3[5];
                  }
                  goto LAB_23e86d7dd;
                }
                plVar13 = *(longlong **)(param_1 + 0x138);
                *plVar13 = *plVar13 + 1;
                uVar18 = FUN_23a3a0d40(DAT_23ed6cf28);
                plVar16 = plRam000000023eed7218;
                lVar10 = *(longlong *)(param_1 + 0x10);
                plVar15 = *(longlong **)(lVar10 + 0xe20);
                if (plVar15 == (longlong *)0x0) {
                  plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar21 = plVar15[3];
                  *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
                  *(longlong *)(lVar10 + 0xe20) = lVar21;
                  *plVar15 = 1;
                }
                plVar15[4] = 0;
                lVar10 = *(longlong *)
                          (*(longlong *)(*(longlong *)(pcStack_e8 + 0x1f8) + 0x10) + 0x2e8);
                lVar21 = plVar15[-1];
                puVar4 = *(undefined8 **)(lVar10 + 8);
                *puVar4 = plVar15 + -2;
                plVar15[-2] = lVar10;
                plVar15[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar4;
                *(longlong **)(lVar10 + 8) = plVar15 + -2;
                *plVar16 = *plVar16 + 1;
                plVar15[3] = (longlong)plVar16;
                uVar5 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 != (longlong *)0x0) {
LAB_23e86df99:
                  uStack_c0 = uVar5;
                  plStack_c8 = plVar13;
                  lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_c8);
                  if (lVar10 == 0) {
                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_b0 = *(code **)(param_1 + 0x68);
                    pcStack_a8 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar15 = *plVar15 + -1;
                    pcVar17 = pcStack_b0;
                    auVar23 = auStack_b8;
                    pcVar20 = pcStack_a8;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                      pcVar17 = pcStack_b0;
                      auVar23 = auStack_b8;
                      pcVar20 = pcStack_a8;
                    }
                  }
                  else {
                    plVar15[4] = lVar10;
                    plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    if (plVar16 != (longlong *)0x0) {
                      *(undefined4 *)(plVar3 + 5) = 0x74;
                      plVar15 = (longlong *)FUN_23e914090(param_1,uVar18);
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                      }
                      if (plVar15 != (longlong *)0x0) {
                        *plVar15 = *plVar15 + -1;
                        if (*plVar15 == 0) {
                          (**(code **)(plVar15[1] + 0x30))(plVar15);
                        }
                        *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        plVar3 = *(longlong **)(param_1 + 0x138);
                        *(longlong **)(param_1 + 0x138) = plVar14;
                        pcVar17 = pcVar20;
                        if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
                          (**(code **)(plVar3[1] + 0x30))();
                        }
                        goto LAB_23e86c66a;
                      }
                    }
                    auVar23 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcVar20 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcVar17 = *(code **)(param_1 + 0x68);
                  }
                  pcStack_a8 = (code *)0x0;
                  _auStack_b8 = (undefined1  [16])0x0;
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  pcVar19 = *(code **)(param_1 + 0x138);
                  iVar7 = 0x74;
LAB_23e86e5f0:
                  *(longlong **)(param_1 + 0x138) = plVar14;
                  if (pcVar19 != (code *)0x0) goto LAB_23e86e460;
                  auStack_b8 = auVar23;
                  pcStack_b0 = pcVar17;
                  if (pcVar20 != (code *)0x0) goto LAB_23e86e4bf;
                  pcStack_a8 = (code *)0x0;
                  goto LAB_23e86e26b;
                }
                plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar16 != (longlong *)0x0) {
                  *plVar16 = *plVar16 + 1;
                  DAT_23ed6a4c0 = plVar16;
                  goto LAB_23e86df99;
                }
                PyErr_PrintEx(0);
                Py_Exit(1);
LAB_23e86ec83:
                plVar12 = (longlong *)FUN_23a3c1b70(param_1,pcVar20,2,4);
                plStack_140 = (longlong *)0x0;
                if (plVar12 != (longlong *)0x0) {
LAB_23e86caa1:
                  plStack_140 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                  if (((plStack_140 == (longlong *)0x0) &&
                      (plStack_140 = (longlong *)FUN_23a3c1b70(param_1,pcVar20,3,4),
                      plStack_140 == (longlong *)0x0)) ||
                     (cVar6 = FUN_23a3884a0(param_1,pcVar20,plVar13,4), cVar6 == '\0'))
                  goto LAB_23e86e7ef;
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if (*plStack_140 == 0) {
                    (**(code **)(plStack_140[1] + 0x30))();
                  }
                  plStack_100 = (longlong *)FUN_23e8c6640(plVar12,plVar9);
                  if (plStack_100 == (longlong *)0x0) {
                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_b0 = *(code **)(param_1 + 0x68);
                    pcStack_a8 = *(code **)(param_1 + 0x70);
                    pcStack_138 = (code *)0x0;
                    uVar22 = 0x58;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_128 = (longlong *)0x0;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    pcStack_118 = (code *)0x0;
                    plStack_108 = (longlong *)0x0;
                    pcStack_f8 = (code *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e86dc95;
                  }
                  pcStack_f8 = (code *)FUN_23e8c6640(plStack_140,plVar11);
                  if (pcStack_f8 != (code *)0x0) {
                    lVar10 = FUN_23e8de4a0();
                    if (lVar10 == 0) {
                      FUN_23e915740(param_1,pcVar20,uRam000000023eed70c0);
                    }
                    else {
                      plVar13 = (longlong *)FUN_23e8bc2f0(lVar10,uRam000000023eed7138);
                      if (plVar13 == (longlong *)0x0) {
LAB_23e86edfe:
                        pcStack_a8 = *(code **)(param_1 + 0x70);
                        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_b0 = *(code **)(param_1 + 0x68);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eed70a8);
                        if (plVar14 != (longlong *)0x0) {
                          *(undefined4 *)(plVar3 + 5) = 0x5b;
                          plStack_108 = (longlong *)FUN_23e914090(param_1,plVar13,plVar14);
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            FUN_23a334bc0();
                          }
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            FUN_23a334bc0();
                          }
                          if (plStack_108 == (longlong *)0x0) goto LAB_23e86edfe;
                          lVar10 = FUN_23e8de350();
                          if (lVar10 == 0) {
                            FUN_23e915740(param_1,pcVar20,uRam000000023eed7140);
                            pcStack_118 = (code *)0x0;
                          }
                          else {
                            *(undefined4 *)(plVar3 + 5) = 0x5c;
                            pcStack_118 = (code *)FUN_23e915840(param_1,lVar10,uRam000000023eed7148,
                                                                plStack_108);
                            if (pcStack_118 != (code *)0x0) {
                              *(undefined4 *)(plVar3 + 5) = 0x5d;
                              plStack_110 = (longlong *)
                                            FUN_23e91bfe0(param_1,pcStack_118,uRam000000023eed7150);
                              if (plStack_110 == (longlong *)0x0) {
                                auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                pcStack_b0 = *(code **)(param_1 + 0x68);
                                pcStack_a8 = *(code **)(param_1 + 0x70);
                                uVar22 = 0x5d;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                pcStack_138 = (code *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              }
                              else {
                                lVar10 = FUN_23e8de350();
                                if (lVar10 == 0) {
                                  FUN_23e915740(param_1,pcVar20,uRam000000023eed7140);
                                  uVar22 = 0x5f;
                                  pcStack_138 = (code *)0x0;
                                  plStack_128 = (longlong *)0x0;
                                  plStack_130 = (longlong *)0x0;
                                  plStack_120 = (longlong *)0x0;
                                }
                                else {
                                  *(undefined4 *)(plVar3 + 5) = 0x5f;
                                  plStack_120 = (longlong *)
                                                FUN_23e91bfe0(param_1,lVar10,uRam000000023eed7158);
                                  if (plStack_120 == (longlong *)0x0) {
                                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    pcStack_b0 = *(code **)(param_1 + 0x68);
                                    pcStack_a8 = *(code **)(param_1 + 0x70);
                                    uVar22 = 0x5f;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    pcStack_138 = (code *)0x0;
                                    plStack_128 = (longlong *)0x0;
                                    plStack_130 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else {
                                    *(undefined4 *)(plVar3 + 5) = 0x60;
                                    auStack_98._8_8_ = plStack_100;
                                    auStack_98._0_8_ = pcStack_118;
                                    pcStack_88 = pcStack_f8;
                                    plVar13 = (longlong *)
                                              FUN_23e9578c0(param_1,plStack_120,uRam000000023eed7160
                                                            ,auStack_98);
                                    if (plVar13 == (longlong *)0x0) {
                                      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                      pcStack_b0 = *(code **)(param_1 + 0x68);
                                      pcStack_a8 = *(code **)(param_1 + 0x70);
                                      uVar22 = 0x60;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      pcStack_138 = (code *)0x0;
                                      plStack_128 = (longlong *)0x0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      plStack_130 = (longlong *)0x0;
                                      goto LAB_23e86dc95;
                                    }
                                    lVar10 = *plVar13;
                                    *plVar13 = lVar10 + -1;
                                    if (lVar10 + -1 == 0) {
                                      FUN_23a334bc0(plVar13);
                                    }
                                    *(undefined4 *)(plVar3 + 5) = 0x61;
                                    plVar13 = (longlong *)
                                              FUN_23e915840(param_1,plStack_110,uRam000000023eed7168
                                                            ,plStack_120);
                                    if (plVar13 != (longlong *)0x0) {
                                      lVar10 = *plVar13;
                                      *plVar13 = lVar10 + -1;
                                      if (lVar10 + -1 == 0) {
                                        FUN_23a334bc0(plVar13);
                                      }
                                      plVar13 = (longlong *)
                                                FUN_23e8bc2f0(plStack_110,uRam000000023eed7170);
                                      uVar18 = uRam000000023eed7120;
                                      if (plVar13 == (longlong *)0x0) {
LAB_23e86f083:
                                        pcStack_a8 = *(code **)(param_1 + 0x70);
                                        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                        pcStack_b0 = *(code **)(param_1 + 0x68);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                      }
                                      else {
                                        plVar14 = (longlong *)
                                                  FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                                        lVar21 = _DAT_23eede1c0;
                                        *plStack_100 = *plStack_100 + 1;
                                        lVar10 = *(longlong *)(lVar21 + 0x20);
                                        plVar14[3] = (longlong)plStack_100;
                                        *(longlong *)pcStack_f8 = *(longlong *)pcStack_f8 + 1;
                                        plVar14[4] = (longlong)pcStack_f8;
                                        uVar5 = uRam000000023eed7120;
                                        if (*(char *)(lVar10 + 10) == '\0') {
                                          plVar15 = (longlong *)
                                                    FUN_23a37a020(lVar21,lRam000000023eed7178);
                                          if (plVar15 == (longlong *)0x0) goto LAB_23e86f290;
                                          lVar21 = *plVar15;
LAB_23e86f287:
                                          if (lVar21 == 0) goto LAB_23e86f290;
LAB_23e86cf0c:
                                          plVar15 = (longlong *)
                                                    FUN_23e8bc2f0(lVar21,uRam000000023eed7180);
                                          if (plVar15 != (longlong *)0x0) {
                                            *(undefined4 *)(plVar3 + 5) = 99;
                                            auStack_98._8_8_ = plVar14;
                                            auStack_98._0_8_ = uVar18;
                                            uStack_80 = uVar5;
                                            pcStack_88 = pcStack_118;
                                            plStack_78 = plVar15;
                                            plVar16 = (longlong *)
                                                      FUN_23e95b390(param_1,plVar13,auStack_98);
                                            *plVar13 = *plVar13 + -1;
                                            if (*plVar13 == 0) {
                                              FUN_23a334bc0(plVar13);
                                            }
                                            lVar10 = *plVar14;
                                            *plVar14 = lVar10 + -1;
                                            if (lVar10 + -1 == 0) {
                                              FUN_23a334bc0(plVar14);
                                            }
                                            *plVar15 = *plVar15 + -1;
                                            if (*plVar15 == 0) {
                                              FUN_23a334bc0(plVar15);
                                            }
                                            if (plVar16 == (longlong *)0x0) goto LAB_23e86f083;
                                            lVar10 = *plVar16;
                                            *plVar16 = lVar10 + -1;
                                            if (lVar10 + -1 == 0) {
                                              FUN_23a334bc0(plVar16);
                                            }
                                            *(undefined4 *)(plVar3 + 5) = 0x65;
                                            plStack_130 = (longlong *)
                                                          FUN_23e91bfe0(param_1,plStack_120,
                                                                        uRam000000023eed7188);
                                            if (plStack_130 == (longlong *)0x0) {
                                              auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                              pcStack_b0 = *(code **)(param_1 + 0x68);
                                              pcStack_a8 = *(code **)(param_1 + 0x70);
                                              uVar22 = 0x65;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              pcStack_138 = (code *)0x0;
                                              plStack_128 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              goto LAB_23e86dc95;
                                            }
                                            *(undefined4 *)(plVar3 + 5) = 0x66;
                                            plStack_128 = (longlong *)
                                                          FUN_23e915840(param_1,plStack_120,
                                                                        uRam000000023eed7190,
                                                                        *(undefined8 *)
                                                                         (lRam000000023eed7198 +
                                                                         0x18));
                                            if (plStack_128 != (longlong *)0x0) {
                                              lVar10 = FUN_23e8dde10();
                                              if (lVar10 == 0) {
                                                FUN_23e915740(param_1,pcVar20,uRam000000023eed71a0);
                                              }
                                              else {
                                                plVar13 = (longlong *)FUN_23e8bc2f0();
                                                if (plVar13 == (longlong *)0x0) {
                                                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  pcStack_b0 = *(code **)(param_1 + 0x68);
                                                  pcStack_a8 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uVar22 = 0x68;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  pcStack_138 = (code *)0x0;
                                                  goto LAB_23e86dc95;
                                                }
                                                lVar10 = FUN_23e8dde10();
                                                if (lVar10 == 0) {
                                                  FUN_23e915740(param_1,pcVar20,uRam000000023eed71a0
                                                               );
                                                }
                                                else {
                                                  plVar14 = (longlong *)
                                                            FUN_23e8bc2f0(lVar10,
                                                  uRam000000023eed71b0);
                                                  if (plVar14 != (longlong *)0x0) {
                                                    *(undefined4 *)(plVar3 + 5) = 0x68;
                                                    auStack_98._0_8_ = plStack_128;
                                                    plStack_c8 = plVar14;
                                                    pcStack_138 = (code *)FUN_23e939900(param_1,
                                                  plVar13,auStack_98,&plStack_c8,
                                                  uRam000000023eed71b8);
                                                  lVar10 = *plVar13;
                                                  *plVar13 = lVar10 + -1;
                                                  if (lVar10 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  *plVar14 = *plVar14 + -1;
                                                  if (*plVar14 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (pcStack_138 == (code *)0x0) {
                                                    auStack_b8 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    pcStack_b0 = *(code **)(param_1 + 0x68);
                                                    pcStack_a8 = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e86f155;
                                                  }
                                                  lVar10 = FUN_23a38cc10(param_1,plStack_130,
                                                                         uRam000000023eed71c0);
                                                  if (lVar10 == 0) {
LAB_23e86f51f:
                                                    auStack_b8 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    pcStack_b0 = *(code **)(param_1 + 0x68);
                                                    pcStack_a8 = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    plVar13 = (longlong *)
                                                              FUN_23e916ad0(*(undefined8 *)
                                                                             (param_1 + 0x10),3);
                                                    plVar13[3] = lVar10;
                                                    lVar10 = FUN_23a38cc10(param_1,plStack_130,
                                                                           uRam000000023eed71c8);
                                                    if (lVar10 != 0) {
                                                      plVar13[4] = lVar10;
                                                      plVar14 = plRam000000023eed71d0;
                                                      *plRam000000023eed71d0 =
                                                           *plRam000000023eed71d0 + 1;
                                                      plVar13[5] = (longlong)plVar14;
                                                      cVar6 = FUN_23e8d9ac0(pcStack_138,
                                                                            uRam000000023eed71d8,
                                                                            plVar13);
                                                      *plVar13 = *plVar13 + -1;
                                                      if (*plVar13 == 0) {
                                                        FUN_23a334bc0(plVar13);
                                                      }
                                                      if (cVar6 == '\0') goto LAB_23e86f51f;
                                                      lVar10 = FUN_23e8de200();
                                                      if (lVar10 == 0) {
                                                        FUN_23e915740(param_1,pcVar20,
                                                                      uRam000000023eed71e0);
                                                      }
                                                      else {
                                                        plVar13 = (longlong *)
                                                                  FUN_23e8bc2f0(lVar10,
                                                  uRam000000023eed71e8);
                                                  if (plVar13 == (longlong *)0x0) {
LAB_23e86f49b:
                                                    auStack_b8 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    pcStack_b0 = *(code **)(param_1 + 0x68);
                                                    pcStack_a8 = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    lVar10 = FUN_23e8de200();
                                                    if (lVar10 == 0) {
                                                      FUN_23e915740(param_1,pcVar20,
                                                                    uRam000000023eed71e0);
                                                      *plVar13 = *plVar13 + -1;
                                                      lVar10 = *plVar13;
                                                    }
                                                    else {
                                                      plVar14 = (longlong *)
                                                                FUN_23e8bc2f0(lVar10,
                                                  uRam000000023eed71f0);
                                                  if (plVar14 != (longlong *)0x0) {
                                                    *(undefined4 *)(plVar3 + 5) = 0x6a;
                                                    auStack_98._8_8_ = plVar14;
                                                    auStack_98._0_8_ = pcStack_138;
                                                    pcVar17 = (code *)FUN_23e94ed00(param_1,plVar13,
                                                                                    auStack_98);
                                                    *plVar13 = *plVar13 + -1;
                                                    if (*plVar13 == 0) {
                                                      FUN_23a334bc0(plVar13);
                                                    }
                                                    *plVar14 = *plVar14 + -1;
                                                    if (*plVar14 == 0) {
                                                      FUN_23a334bc0(plVar14);
                                                    }
                                                    if (pcVar17 == (code *)0x0) goto LAB_23e86f49b;
                                                    *(longlong *)pcStack_138 =
                                                         *(longlong *)pcStack_138 + -1;
                                                    if (*(longlong *)pcStack_138 == 0) {
                                                      FUN_23a334bc0(pcStack_138);
                                                    }
                                                    lVar10 = FUN_23e8de4a0();
                                                    pcStack_138 = pcVar17;
                                                    if (lVar10 == 0) {
                                                      FUN_23e915740(param_1,pcVar20,
                                                                    uRam000000023eed70c0);
                                                    }
                                                    else {
                                                      plVar13 = (longlong *)
                                                                FUN_23e8bc2f0(lVar10,
                                                  uRam000000023eed71f8);
                                                  if (plVar13 != (longlong *)0x0) {
                                                    *(undefined4 *)(plVar3 + 5) = 0x6c;
                                                    plVar14 = (longlong *)
                                                              FUN_23e91bfe0(param_1,plStack_120,
                                                                            uRam000000023eed7200);
                                                    if (plVar14 == (longlong *)0x0) {
                                                      auStack_b8 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      pcStack_b0 = *(code **)(param_1 + 0x68);
                                                      pcStack_a8 = *(code **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar13 = *plVar13 + -1;
                                                      if (*plVar13 == 0) {
                                                        FUN_23a334bc0(plVar13);
                                                      }
                                                      goto LAB_23e86f3dd;
                                                    }
                                                    *(undefined4 *)(plVar3 + 5) = 0x6c;
                                                    plVar15 = (longlong *)
                                                              FUN_23e914090(param_1,plVar13);
                                                    *plVar13 = *plVar13 + -1;
                                                    if (*plVar13 == 0) {
                                                      FUN_23a334bc0(plVar13);
                                                    }
                                                    *plVar14 = *plVar14 + -1;
                                                    if (*plVar14 == 0) {
                                                      FUN_23a334bc0(plVar14);
                                                    }
                                                    if (plVar15 != (longlong *)0x0) {
                                                      *plVar15 = *plVar15 + -1;
                                                      if (*plVar15 == 0) {
                                                        FUN_23a334bc0(plVar15);
                                                      }
                                                      *(undefined4 *)(plVar3 + 5) = 0x6d;
                                                      plVar13 = (longlong *)
                                                                FUN_23e91bfe0(param_1,plStack_110,
                                                                              uRam000000023eed7208);
                                                      if (plVar13 == (longlong *)0x0) {
                                                        auStack_b8 = *(undefined1 (*) [8])
                                                                      (param_1 + 0x60);
                                                        pcStack_b0 = *(code **)(param_1 + 0x68);
                                                        pcStack_a8 = *(code **)(param_1 + 0x70);
                                                        uVar22 = 0x6d;
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                      }
                                                      else {
                                                        *plVar13 = *plVar13 + -1;
                                                        if (*plVar13 == 0) {
                                                          FUN_23a334bc0(plVar13);
                                                        }
                                                        *(undefined4 *)(plVar3 + 5) = 0x6e;
                                                        plVar13 = (longlong *)
                                                                  FUN_23e91bfe0(param_1,pcStack_118)
                                                        ;
                                                        if (plVar13 == (longlong *)0x0) {
                                                          auStack_b8 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          pcStack_b0 = *(code **)(param_1 + 0x68);
                                                          pcStack_a8 = *(code **)(param_1 + 0x70);
                                                          uVar22 = 0x6e;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                        }
                                                        else {
                                                          *plVar13 = *plVar13 + -1;
                                                          if (*plVar13 == 0) {
                                                            FUN_23a334bc0(plVar13);
                                                          }
                                                          lVar10 = FUN_23e8de4a0();
                                                          if (lVar10 == 0) {
                                                            FUN_23e915740(param_1,pcVar20,
                                                                          uRam000000023eed70c0);
                                                          }
                                                          else {
                                                            plVar13 = (longlong *)
                                                                      FUN_23e8bc2f0(lVar10,
                                                  uRam000000023eed7210);
                                                  if (plVar13 != (longlong *)0x0) {
                                                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar2);
                                                    if (plVar14 == (longlong *)0x0) {
                                                      auStack_b8 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      pcStack_b0 = *(code **)(param_1 + 0x68);
                                                      pcStack_a8 = *(code **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar13 = *plVar13 + -1;
                                                      if (*plVar13 == 0) {
                                                        FUN_23a334bc0(plVar13);
                                                      }
                                                      goto LAB_23e86effb;
                                                    }
                                                    *(undefined4 *)(plVar3 + 5) = 0x6f;
                                                    auStack_98._8_8_ = plStack_108;
                                                    auStack_98._0_8_ = plVar14;
                                                    plVar15 = (longlong *)
                                                              FUN_23e94ed00(param_1,plVar13,
                                                                            auStack_98);
                                                    *plVar13 = *plVar13 + -1;
                                                    if (*plVar13 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    *plVar14 = *plVar14 + -1;
                                                    if (*plVar14 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar15 != (longlong *)0x0) {
                                                      *plVar15 = *plVar15 + -1;
                                                      if (*plVar15 == 0) {
                                                        FUN_23a334bc0(plVar15);
                                                      }
                                                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38))
                                                      ;
                                                      *(longlong *)pcVar17 =
                                                           *(longlong *)pcVar17 + 1;
                                                      *plVar9 = *plVar9 + -1;
                                                      if (*plVar9 != 0) {
                                                        *plVar11 = *plVar11 + -1;
                                                        if (*plVar11 == 0) goto LAB_23e86d670;
                                                        goto LAB_23e86c6dc;
                                                      }
                                                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                                                      goto LAB_23e86c6cc;
                                                    }
                                                  }
                                                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  pcStack_b0 = *(code **)(param_1 + 0x68);
                                                  pcStack_a8 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
LAB_23e86effb:
                                                  uVar22 = 0x6f;
                                                  }
                                                  }
                                                  goto LAB_23e86dc95;
                                                  }
                                                  }
                                                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  pcStack_b0 = *(code **)(param_1 + 0x68);
                                                  pcStack_a8 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
LAB_23e86f3dd:
                                                  uVar22 = 0x6c;
                                                  goto LAB_23e86dc95;
                                                  }
                                                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  pcStack_b0 = *(code **)(param_1 + 0x68);
                                                  pcStack_a8 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar13 = *plVar13 + -1;
                                                  lVar10 = *plVar13;
                                                  }
                                                  if (lVar10 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                  }
                                                  }
                                                  }
                                                  uVar22 = 0x6a;
                                                  goto LAB_23e86dc95;
                                                  }
                                                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  pcStack_b0 = *(code **)(param_1 + 0x68);
                                                  pcStack_a8 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                  }
                                                  }
                                                  uVar22 = 0x69;
                                                  goto LAB_23e86dc95;
                                                  }
                                                  pcStack_a8 = *(code **)(param_1 + 0x70);
                                                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  pcStack_b0 = *(code **)(param_1 + 0x68);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                }
                                                lVar10 = *plVar13;
                                                *plVar13 = lVar10 + -1;
                                                if (lVar10 + -1 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                              }
LAB_23e86f155:
                                              uVar22 = 0x68;
                                              pcStack_138 = (code *)0x0;
                                              goto LAB_23e86dc95;
                                            }
                                            auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            pcStack_b0 = *(code **)(param_1 + 0x68);
                                            pcStack_a8 = *(code **)(param_1 + 0x70);
                                            uVar22 = 0x66;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            pcStack_138 = (code *)0x0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            goto LAB_23e86dc95;
                                          }
                                          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                          pcStack_b0 = *(code **)(param_1 + 0x68);
                                          pcStack_a8 = *(code **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar13 = *plVar13 + -1;
                                          lVar10 = *plVar13;
                                        }
                                        else {
                                          iVar7 = *(int *)(lVar10 + 0xc);
                                          if (*(int *)(lVar10 + 0xc) == 0) {
                                            *(int *)(lVar10 + 0xc) = _DAT_23ec15654;
                                            iVar7 = _DAT_23ec15654;
                                            _DAT_23ec15654 = _DAT_23ec15654 + 1;
                                          }
                                          if (_DAT_23ec1564c != iVar7) {
                                            _DAT_23ec1564c = iVar7;
                                            _DAT_23eeded30 =
                                                 FUN_23e8cbd60(lVar10,lRam000000023eed7178,
                                                               *(undefined8 *)
                                                                (lRam000000023eed7178 + 0x18));
                                          }
                                          if (-1 < _DAT_23eeded30) {
                                            lVar1 = lVar10 + 0x20 +
                                                    (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                                            lVar21 = *(longlong *)
                                                      (lVar1 + 8 + _DAT_23eeded30 * 0x10);
                                            if (lVar21 != 0) goto LAB_23e86cf0c;
                                            _DAT_23eeded30 =
                                                 FUN_23e8cbd60(lVar10,lRam000000023eed7178,
                                                               *(undefined8 *)
                                                                (lRam000000023eed7178 + 0x18));
                                            if (-1 < _DAT_23eeded30) {
                                              lVar21 = *(longlong *)
                                                        (lVar1 + 8 + _DAT_23eeded30 * 0x10);
                                              goto LAB_23e86f287;
                                            }
                                          }
LAB_23e86f290:
                                          plVar15 = (longlong *)
                                                    FUN_23a37a020(DAT_23ed6ccc0,lRam000000023eed7178
                                                                 );
                                          if ((plVar15 != (longlong *)0x0) &&
                                             (lVar21 = *plVar15, lVar21 != 0)) goto LAB_23e86cf0c;
                                          FUN_23e915740(param_1,pcVar20,lRam000000023eed7178);
                                          *plVar13 = *plVar13 + -1;
                                          lVar10 = *plVar13;
                                        }
                                        if (lVar10 == 0) {
                                          FUN_23a334bc0(plVar13);
                                        }
                                        lVar10 = *plVar14;
                                        *plVar14 = lVar10 + -1;
                                        if (lVar10 + -1 == 0) {
                                          FUN_23a334bc0(plVar14);
                                        }
                                      }
                                      uVar22 = 99;
                                      pcStack_138 = (code *)0x0;
                                      plStack_128 = (longlong *)0x0;
                                      plStack_130 = (longlong *)0x0;
                                      goto LAB_23e86dc95;
                                    }
                                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    pcStack_b0 = *(code **)(param_1 + 0x68);
                                    pcStack_a8 = *(code **)(param_1 + 0x70);
                                    uVar22 = 0x61;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    pcStack_138 = (code *)0x0;
                                    plStack_128 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plStack_130 = (longlong *)0x0;
                                  }
                                }
                              }
                              goto LAB_23e86dc95;
                            }
                            pcStack_a8 = *(code **)(param_1 + 0x70);
                            auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pcStack_b0 = *(code **)(param_1 + 0x68);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          }
                          uVar22 = 0x5c;
                          pcStack_138 = (code *)0x0;
                          plStack_128 = (longlong *)0x0;
                          plStack_130 = (longlong *)0x0;
                          plStack_120 = (longlong *)0x0;
                          plStack_110 = (longlong *)0x0;
                          goto LAB_23e86dc95;
                        }
                        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_b0 = *(code **)(param_1 + 0x68);
                        pcStack_a8 = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0(plVar13);
                        }
                      }
                    }
                    uVar22 = 0x5b;
                    pcStack_138 = (code *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    pcStack_118 = (code *)0x0;
                    plStack_108 = (longlong *)0x0;
                    goto LAB_23e86dc95;
                  }
                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_b0 = *(code **)(param_1 + 0x68);
                  pcStack_a8 = *(code **)(param_1 + 0x70);
                  pcStack_138 = (code *)0x0;
                  uVar22 = 0x59;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plStack_128 = (longlong *)0x0;
                  plStack_130 = (longlong *)0x0;
                  plStack_120 = (longlong *)0x0;
                  plStack_110 = (longlong *)0x0;
                  pcStack_118 = (code *)0x0;
                  plStack_108 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e86dc95;
                }
LAB_23e86e7ef:
                pcVar17 = pcStack_a8;
                pcVar20 = pcStack_b0;
                auVar23 = auStack_b8;
                pcStack_a8 = (code *)0x0;
                _auStack_b8 = (undefined1  [16])0x0;
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                pcStack_a8 = (code *)0x0;
                auStack_b8 = (undefined1  [8])0x0;
                pcStack_b0 = (code *)0x0;
                if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                if ((plStack_140 != (longlong *)0x0) &&
                   (lVar10 = *plStack_140, *plStack_140 = lVar10 + -1, lVar10 + -1 == 0)) {
                  (**(code **)(plStack_140[1] + 0x30))(plStack_140);
                }
              } while( true );
            }
            goto LAB_23e86e100;
          }
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          pcStack_a8 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (pcStack_a8 != (code *)0x0) {
            plVar9 = *(longlong **)(pcStack_a8 + 0x18);
            goto joined_r0x00023e86d737;
          }
        }
      }
    }
  }
  plVar12 = (longlong *)0x0;
  plVar11 = (longlong *)0x0;
  plVar9 = (longlong *)0x0;
  pcStack_138 = (code *)0x0;
  iVar7 = 0x53;
  plStack_128 = (longlong *)0x0;
  plStack_130 = (longlong *)0x0;
  plStack_120 = (longlong *)0x0;
  plStack_110 = (longlong *)0x0;
  pcStack_118 = (code *)0x0;
  plStack_108 = (longlong *)0x0;
  pcStack_f8 = (code *)0x0;
  plStack_100 = (longlong *)0x0;
  plStack_140 = (longlong *)0x0;
  pcStack_e8 = _PyRuntime_exref;
LAB_23e86e26b:
  pcVar20 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    pcVar17 = pcStack_a8;
  }
  else {
    pcVar17 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar17;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    pcVar17 = (code *)0x0;
  }
  *(longlong **)(pcVar20 + 0x18) = plVar3;
  *(longlong *)(pcVar20 + 0x10) = 0;
  *plVar3 = *plVar3 + 1;
  lVar10 = *(longlong *)(pcStack_e8 + 0x1f8);
  *(int *)(pcVar20 + 0x24) = iVar7;
  *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
  lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
  lVar21 = *(longlong *)(pcVar20 + -8);
  plVar13 = *(longlong **)(lVar10 + 8);
  *plVar13 = (longlong)(pcVar20 + -0x10);
  *(longlong *)(pcVar20 + -0x10) = lVar10;
  *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)plVar13;
  *(code **)(lVar10 + 8) = pcVar20 + -0x10;
  if ((pcVar17 != (code *)0x0) &&
     (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
  }
LAB_23e86d888:
  pcStack_a8 = pcVar20;
  FUN_23e8bba40(plVar3,"ooooooooooooooo",plVar2,plVar9,plVar11,plVar12,plStack_140,plStack_100,
                pcStack_f8,plStack_108,pcStack_118,plStack_110,plStack_120,plStack_130,plStack_128,
                pcStack_138,0);
  if (_DAT_23eeded40 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeded40 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar10 + 0x28);
  plVar13 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  pcVar20 = pcStack_a8;
  pcVar17 = pcStack_b0;
  auVar23 = auStack_b8;
  plVar3[0xf] = 0;
  _auStack_b8 = (undefined1  [16])0x0;
  pcStack_a8 = (code *)0x0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plStack_140 != (longlong *)0x0) &&
     (lVar10 = *plStack_140, *plStack_140 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_140[1] + 0x30))(plStack_140);
  }
  if ((plStack_100 != (longlong *)0x0) &&
     (lVar10 = *plStack_100, *plStack_100 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_100[1] + 0x30))(plStack_100);
  }
  if ((pcStack_f8 != (code *)0x0) &&
     (lVar10 = *(longlong *)pcStack_f8, *(longlong *)pcStack_f8 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_f8 + 8) + 0x30))(pcStack_f8);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar10 = *plStack_108, *plStack_108 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((pcStack_118 != (code *)0x0) &&
     (lVar10 = *(longlong *)pcStack_118, *(longlong *)pcStack_118 = lVar10 + -1, lVar10 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_118 + 8) + 0x30))(pcStack_118);
  }
  if ((plStack_110 != (longlong *)0x0) &&
     (lVar10 = *plStack_110, *plStack_110 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_110[1] + 0x30))(plStack_110);
  }
  if ((plStack_120 != (longlong *)0x0) &&
     (lVar10 = *plStack_120, *plStack_120 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_120[1] + 0x30))(plStack_120);
  }
  if ((plStack_130 != (longlong *)0x0) &&
     (lVar10 = *plStack_130, *plStack_130 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_130[1] + 0x30))(plStack_130);
  }
  if ((plStack_128 != (longlong *)0x0) &&
     (lVar10 = *plStack_128, *plStack_128 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_128[1] + 0x30))(plStack_128);
  }
  if ((pcStack_138 != (code *)0x0) &&
     (lVar10 = *(longlong *)pcStack_138, *(longlong *)pcStack_138 = lVar10 + -1, lVar10 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_138 + 8) + 0x30))();
  }
  *plVar2 = *plVar2 + -1;
  pcStack_a8 = pcVar20;
  auStack_b8 = auVar23;
  pcStack_b0 = pcVar17;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,auStack_b8,pcStack_b0,pcStack_a8);
  return (code *)0x0;
}
