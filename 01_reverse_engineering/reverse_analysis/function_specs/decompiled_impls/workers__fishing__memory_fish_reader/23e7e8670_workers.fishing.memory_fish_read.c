/* ===== 23e7e8670 workers.fishing.memory_fish_read:c1280 ===== */
/* ghidra_name=FUN_23e7e8670 entry=23e7e8670 size=10031 */

longlong * FUN_23e7e8670(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  undefined8 *puVar4;
  char cVar5;
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
  longlong *plVar16;
  code *pcVar17;
  longlong *plVar18;
  int iVar19;
  longlong *plVar20;
  longlong *plVar21;
  undefined4 uVar22;
  undefined8 uVar23;
  longlong *local_140;
  longlong *local_138;
  longlong *local_130;
  longlong *local_128;
  longlong *local_120;
  longlong *local_118;
  longlong *local_110;
  longlong *local_108;
  longlong *local_e8;
  longlong *local_e0;
  longlong *local_c0;
  longlong *local_b8;
  undefined1 local_a8 [16];
  longlong *local_98 [2];
  longlong *local_88;
  longlong *plStack_80;
  longlong *local_78;
  
  lVar3 = DAT_23ed6cce8;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  lVar9 = *(longlong *)(param_1 + 0x10);
  local_a8 = (undefined1  [16])0x0;
  plVar7 = *(longlong **)(DAT_23ed6cce8 + 0x20);
  iVar19 = *(int *)(lVar9 + 0x1410);
  local_98[0] = (longlong *)0x0;
  *plVar7 = *plVar7 + 1;
  if (iVar19 == 0) {
    local_140 = (longlong *)FUN_23a33a530(PyDict_Type_exref);
    plVar7 = *(longlong **)(lVar3 + 0x20);
  }
  else {
    iVar19 = iVar19 + -1;
    *(int *)(lVar9 + 0x1410) = iVar19;
    local_140 = *(longlong **)(lVar9 + 0x1190 + (longlong)iVar19 * 8);
    *local_140 = 1;
  }
  plVar6 = DAT_23eedeb20;
  lVar9 = *(longlong *)(lVar3 + 0x28);
  local_140[4] = (longlong)plVar7;
  local_140[5] = lVar9;
  local_140[2] = 0;
  local_140[3] = 1;
  if (plVar6 == (longlong *)0x0) {
LAB_23e7e8751:
    plVar6 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eedeb18,DAT_23eedebc0,0x60);
    DAT_23eedeb20 = plVar6;
  }
  else {
    lVar9 = *plVar6;
    if (1 < lVar9) {
      *plVar6 = lVar9 + -1;
      goto LAB_23e7e8751;
    }
    if (plVar6[2] != 0) {
      *plVar6 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23e7e8751;
    }
  }
  lVar9 = *(longlong *)(param_1 + 0x38);
  lVar3 = *(longlong *)(lVar9 + 8);
  plVar6[0xf] = lVar3;
  *(longlong **)(lVar9 + 8) = plVar6 + 9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar6[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar6[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  *plVar6 = *plVar6 + 1;
  *(undefined4 *)(plVar6 + 8) = 0;
  plVar7 = (longlong *)FUN_23ebf7180(plVar1);
  if (plVar7 == (longlong *)0x0) {
    local_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar21 = *(longlong **)(param_1 + 0x70);
    plVar15 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar22 = 0x75;
    local_e0 = (longlong *)0x0;
    local_e8 = (longlong *)0x0;
    local_120 = (longlong *)0x0;
    local_130 = (longlong *)0x0;
    local_128 = (longlong *)0x0;
    local_110 = (longlong *)0x0;
    local_138 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e7e93fa;
  }
  local_e0 = (longlong *)0x0;
  plVar15 = (longlong *)0x0;
  plVar16 = (longlong *)0x0;
  local_b8 = (longlong *)0x0;
  local_120 = (longlong *)0x0;
  local_108 = (longlong *)0x0;
  local_118 = (longlong *)0x0;
  plVar10 = (longlong *)0x0;
  plVar12 = (longlong *)0x0;
  plVar8 = (longlong *)0x0;
  while( true ) {
    pcVar17 = *(code **)(plVar7[1] + 0xe0);
    if (pcVar17 == (code *)0x0) break;
    local_c0 = (longlong *)(*pcVar17)(plVar7);
    if (local_c0 == (longlong *)0x0) goto LAB_23e7e9f06;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    plVar8 = (longlong *)FUN_23a388310(local_c0);
    if (plVar8 == (longlong *)0x0) {
      pcVar17 = *(code **)(param_1 + 0x60);
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      plVar21 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e7ea330;
    }
    local_138 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
    if ((local_138 == (longlong *)0x0) &&
       (local_138 = (longlong *)FUN_23a3c1b70(param_1,local_a8,0,4), local_138 == (longlong *)0x0))
    {
      local_130 = (longlong *)0x0;
      lVar9 = *plVar8;
      local_128 = (longlong *)0x0;
      local_110 = (longlong *)0x0;
LAB_23e7ea1bb:
      plVar21 = local_98[0];
      pcVar17 = (code *)local_a8._0_8_;
      uVar13 = local_a8._8_8_;
      local_a8 = (undefined1  [16])0x0;
      local_98[0] = (longlong *)0x0;
      *plVar8 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      local_98[0] = (longlong *)0x0;
      local_a8 = (undefined1  [16])0x0;
      if ((local_138 != (longlong *)0x0) &&
         (lVar9 = *local_138, *local_138 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_138[1] + 0x30))(local_138);
      }
      if ((local_110 != (longlong *)0x0) &&
         (lVar9 = *local_110, *local_110 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_110[1] + 0x30))(local_110);
      }
      if ((local_128 != (longlong *)0x0) &&
         (lVar9 = *local_128, *local_128 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_128[1] + 0x30))(local_128);
      }
      if ((local_130 != (longlong *)0x0) &&
         (lVar9 = *local_130, *local_130 = lVar9 + -1, lVar9 + -1 == 0)) {
        (**(code **)(local_130[1] + 0x30))(local_130);
      }
      goto LAB_23e7ea330;
    }
    local_110 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
    if ((local_110 == (longlong *)0x0) &&
       (local_110 = (longlong *)FUN_23a3c1b70(param_1,local_a8,1,4), local_110 == (longlong *)0x0))
    {
      local_130 = (longlong *)0x0;
      lVar9 = *plVar8;
      local_128 = (longlong *)0x0;
      goto LAB_23e7ea1bb;
    }
    local_128 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
    if ((local_128 == (longlong *)0x0) &&
       (local_128 = (longlong *)FUN_23a3c1b70(param_1,local_a8,2,4), local_128 == (longlong *)0x0))
    {
      local_130 = (longlong *)0x0;
      lVar9 = *plVar8;
      goto LAB_23e7ea1bb;
    }
    local_130 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
    if ((local_130 == (longlong *)0x0) &&
       (local_130 = (longlong *)FUN_23a3c1b70(param_1,local_a8,3,4), local_130 == (longlong *)0x0))
    {
      lVar9 = *plVar8;
      goto LAB_23e7ea1bb;
    }
    cVar5 = FUN_23a3884a0(param_1,local_a8,plVar8,4);
    lVar9 = *plVar8;
    if (cVar5 == '\0') goto LAB_23e7ea1bb;
    *plVar8 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    lVar9 = *local_138;
    *local_138 = lVar9 + 1;
    if (local_118 != (longlong *)0x0) {
      lVar9 = *local_118;
      *local_118 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(local_118[1] + 0x30))(local_118);
      }
      lVar9 = *local_138 + -1;
    }
    *local_138 = lVar9;
    if (lVar9 == 0) {
      (**(code **)(local_138[1] + 0x30))(local_138);
    }
    lVar9 = *local_110;
    *local_110 = lVar9 + 1;
    if (local_108 == (longlong *)0x0) {
LAB_23e7e8a00:
      *local_110 = lVar9;
    }
    else {
      lVar9 = *local_108;
      *local_108 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        (**(code **)(local_108[1] + 0x30))();
        lVar9 = *local_110 + -1;
        goto LAB_23e7e8a00;
      }
      lVar9 = *local_110 + -1;
      *local_110 = lVar9;
    }
    if (lVar9 == 0) {
      (**(code **)(local_110[1] + 0x30))();
    }
    lVar9 = *local_128;
    *local_128 = lVar9 + 1;
    if (plVar12 == (longlong *)0x0) {
LAB_23e7e8a56:
      *local_128 = lVar9;
    }
    else {
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
        lVar9 = *local_128 + -1;
        goto LAB_23e7e8a56;
      }
      lVar9 = *local_128 + -1;
      *local_128 = lVar9;
    }
    if (lVar9 == 0) {
      (**(code **)(local_128[1] + 0x30))();
    }
    lVar9 = *local_130;
    *local_130 = lVar9 + 1;
    if (plVar10 == (longlong *)0x0) {
LAB_23e7e8aac:
      *local_130 = lVar9;
    }
    else {
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        lVar9 = *local_130 + -1;
        goto LAB_23e7e8aac;
      }
      lVar9 = *local_130 + -1;
      *local_130 = lVar9;
    }
    if (lVar9 == 0) {
      (**(code **)(local_130[1] + 0x30))();
    }
    if (plVar2 == (longlong *)0x0) {
      local_a8._8_8_ =
           PyUnicode_FromFormat
                     ("cannot access local variable \'%U\' where it is not associated with a value",
                      DAT_23eeddce8);
      local_a8._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
      *(longlong *)local_a8._0_8_ = *(longlong *)local_a8._0_8_ + 1;
      local_98[0] = (longlong *)0x0;
      if ((code *)local_a8._0_8_ != _Py_NoneStruct_exref) {
        FUN_23e91b1b0(param_1,local_a8,local_a8 + 8,local_98);
      }
      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),local_a8._8_8_);
      plVar21 = local_98[0];
      pcVar17 = (code *)local_a8._0_8_;
      uVar13 = local_a8._8_8_;
LAB_23e7ea8ab:
      uVar22 = 0x76;
      local_e8 = local_b8;
      goto LAB_23e7e937e;
    }
    plVar10 = (longlong *)FUN_23e97e310(param_1,DAT_23ed6ccf0,local_130,plVar2);
    if (plVar10 == (longlong *)0x0) {
LAB_23e7ea880:
      plVar21 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar17 = *(code **)(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      goto LAB_23e7ea8ab;
    }
    plVar11 = (longlong *)FUN_23ebf7180(plVar10);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 == (longlong *)0x0) goto LAB_23e7ea880;
    plVar20 = (longlong *)0x0;
LAB_23e7e8b33:
    plVar10 = (longlong *)(**(code **)(plVar11[1] + 0xe0))();
    if (plVar10 != (longlong *)0x0) {
      if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
        (**(code **)(plVar20[1] + 0x30))(plVar20);
      }
      *plVar10 = *plVar10 + 1;
      if ((local_120 != (longlong *)0x0) && (*local_120 = *local_120 + -1, *local_120 == 0)) {
        (**(code **)(local_120[1] + 0x30))(local_120);
      }
      lVar9 = FUN_23e8dd7c0();
      plVar20 = plVar10;
      local_120 = plVar10;
      if (lVar9 != 0) {
        plVar12 = (longlong *)FUN_23e8c09e0(local_128,plVar10);
        if (plVar12 == (longlong *)0x0) {
LAB_23e7ea900:
          plVar21 = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          pcVar17 = *(code **)(param_1 + 0x60);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar13 = *(undefined8 *)(param_1 + 0x68);
          goto LAB_23e7ea56c;
        }
        uVar13 = FUN_23a3a0d40(DAT_23eeddd00);
        plVar10 = (longlong *)FUN_23e8c6640(local_130,plVar10);
        if (plVar10 == (longlong *)0x0) {
LAB_23e7ea940:
          local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
          local_98[0] = *(longlong **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar12 = *plVar12 + -1;
          plVar21 = local_98[0];
          pcVar17 = (code *)local_a8._0_8_;
          uVar13 = local_a8._8_8_;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
            plVar21 = local_98[0];
            pcVar17 = (code *)local_a8._0_8_;
            uVar13 = local_a8._8_8_;
          }
          goto LAB_23e7ea56c;
        }
        *(undefined4 *)(plVar6 + 5) = 0x77;
        local_88 = plVar2;
        plStack_80 = plVar10;
        plVar8 = (longlong *)FUN_23e94ed00(param_1,uVar13,&local_88);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar8 == (longlong *)0x0) goto LAB_23e7ea940;
        *(undefined4 *)(plVar6 + 5) = 0x77;
        local_88 = local_110;
        plStack_80 = plVar12;
        local_78 = plVar8;
        local_e8 = (longlong *)FUN_23e956150(param_1,lVar9,&local_88);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (local_e8 == (longlong *)0x0) goto LAB_23e7ea900;
        if ((local_b8 != (longlong *)0x0) &&
           (lVar9 = *local_b8, *local_b8 = lVar9 + -1, lVar9 + -1 == 0)) {
          (**(code **)(local_b8[1] + 0x30))(local_b8);
        }
        lVar9 = *(longlong *)(DAT_23eeddba8 + 0x20);
        if (*(char *)(lVar9 + 10) == '\0') {
          plVar10 = (longlong *)FUN_23a37a020(DAT_23eeddba8,DAT_23eedddb0);
          if (plVar10 == (longlong *)0x0) goto LAB_23e7e9279;
          lVar9 = *plVar10;
LAB_23e7ea648:
          if (lVar9 == 0) goto LAB_23e7e9279;
        }
        else {
          iVar19 = *(int *)(lVar9 + 0xc);
          if (*(int *)(lVar9 + 0xc) == 0) {
            *(int *)(lVar9 + 0xc) = DAT_23ec15618;
            iVar19 = DAT_23ec15618;
            DAT_23ec15618 = DAT_23ec15618 + 1;
          }
          if (DAT_23ec155f8 != iVar19) {
            DAT_23ec155f8 = iVar19;
            DAT_23eedeb10 = FUN_23e8cbd60(lVar9,DAT_23eedddb0,*(undefined8 *)(DAT_23eedddb0 + 0x18))
            ;
          }
          if (-1 < DAT_23eedeb10) {
            lVar3 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
            if (*(longlong *)(lVar3 + 8 + DAT_23eedeb10 * 0x10) != 0) goto LAB_23e7e8d58;
            DAT_23eedeb10 = FUN_23e8cbd60(lVar9,DAT_23eedddb0,*(undefined8 *)(DAT_23eedddb0 + 0x18))
            ;
            if (-1 < DAT_23eedeb10) {
              lVar9 = *(longlong *)(lVar3 + 8 + DAT_23eedeb10 * 0x10);
              goto LAB_23e7ea648;
            }
          }
LAB_23e7e9279:
          plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedddb0);
          if ((plVar10 == (longlong *)0x0) || (*plVar10 == 0)) {
            uVar22 = 0x78;
            FUN_23e915740(param_1,local_a8,DAT_23eedddb0);
            plVar21 = local_98[0];
            pcVar17 = (code *)local_a8._0_8_;
            uVar13 = local_a8._8_8_;
            goto LAB_23e7e9310;
          }
        }
LAB_23e7e8d58:
        *(undefined4 *)(plVar6 + 5) = 0x78;
        plVar10 = (longlong *)FUN_23e914090(param_1);
        if (plVar10 == (longlong *)0x0) {
LAB_23e7ea9b8:
          plVar21 = *(longlong **)(param_1 + 0x70);
          pcVar17 = *(code **)(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          uVar22 = 0x78;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          uVar13 = *(undefined8 *)(param_1 + 0x68);
        }
        else {
          local_108 = (longlong *)FUN_23ebf7180(plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (local_108 == (longlong *)0x0) goto LAB_23e7ea9b8;
          local_118 = (longlong *)0x0;
LAB_23e7e8dbd:
          if (*(code **)(local_108[1] + 0xe0) != (code *)0x0) {
            plVar14 = (longlong *)(**(code **)(local_108[1] + 0xe0))(local_108);
            if (plVar14 == (longlong *)0x0) goto LAB_23e7e9b16;
            if ((local_118 != (longlong *)0x0) && (*local_118 = *local_118 + -1, *local_118 == 0)) {
              (**(code **)(local_118[1] + 0x30))(local_118);
            }
            plVar8 = (longlong *)FUN_23a388310(plVar14);
            if (plVar8 != (longlong *)0x0) {
              plVar10 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
              if ((plVar10 == (longlong *)0x0) &&
                 (plVar10 = (longlong *)FUN_23a3c1b70(param_1,local_a8,0,2),
                 plVar10 == (longlong *)0x0)) {
                lVar9 = *plVar8;
                plVar12 = (longlong *)0x0;
LAB_23e7e9c6b:
                plVar21 = local_98[0];
                pcVar17 = (code *)local_a8._0_8_;
                uVar13 = local_a8._8_8_;
                local_a8 = (undefined1  [16])0x0;
                local_98[0] = (longlong *)0x0;
                *plVar8 = lVar9 + -1;
                if (lVar9 + -1 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                local_98[0] = (longlong *)0x0;
                local_a8 = (undefined1  [16])0x0;
                if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                goto LAB_23e7e9d1a;
              }
              plVar12 = (longlong *)(**(code **)(plVar8[1] + 0xe0))(plVar8);
              if ((plVar12 == (longlong *)0x0) &&
                 (plVar12 = (longlong *)FUN_23a3c1b70(param_1,local_a8,1,2),
                 plVar12 == (longlong *)0x0)) {
                lVar9 = *plVar8;
                goto LAB_23e7e9c6b;
              }
              cVar5 = FUN_23a3884a0(param_1,local_a8,plVar8,2);
              lVar9 = *plVar8;
              if (cVar5 == '\0') goto LAB_23e7e9c6b;
              *plVar8 = lVar9 + -1;
              if (lVar9 + -1 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              lVar9 = *plVar10;
              *plVar10 = lVar9 + 1;
              if (plVar16 != (longlong *)0x0) {
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                lVar9 = *plVar10 + -1;
              }
              *plVar10 = lVar9;
              if (lVar9 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              lVar9 = *plVar12;
              *plVar12 = lVar9 + 1;
              if (plVar15 != (longlong *)0x0) {
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                lVar9 = *plVar12 + -1;
              }
              *plVar12 = lVar9;
              if (lVar9 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              plVar21 = DAT_23ed6cd28;
              if (DAT_23ed6a4c0 != (longlong *)0x0) {
LAB_23e7e8f31:
                plStack_80 = plVar21;
                local_88 = plVar10;
                plVar15 = (longlong *)FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                if (plVar15 == (longlong *)0x0) {
LAB_23e7ea5a0:
                  pcVar17 = *(code **)(param_1 + 0x60);
                  uVar13 = *(undefined8 *)(param_1 + 0x68);
                  plVar21 = *(longlong **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar22 = 0x79;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar16 = plVar10;
                  plVar15 = plVar12;
                  local_118 = plVar14;
                }
                else {
                  lVar9 = *(longlong *)(param_1 + 0x10);
                  plVar16 = *(longlong **)(lVar9 + 0xe28);
                  if (plVar16 == (longlong *)0x0) {
                    plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                  }
                  else {
                    lVar3 = plVar16[3];
                    *(int *)(lVar9 + 0xec0) = *(int *)(lVar9 + 0xec0) + -1;
                    *(longlong *)(lVar9 + 0xe28) = lVar3;
                    *plVar16 = 1;
                  }
                  pcVar17 = _PyRuntime_exref;
                  plVar16[5] = 0;
                  lVar9 = *(longlong *)
                           (*(longlong *)(*(longlong *)(pcVar17 + 0x1f8) + 0x10) + 0x2e8);
                  lVar3 = plVar16[-1];
                  puVar4 = *(undefined8 **)(lVar9 + 8);
                  *puVar4 = plVar16 + -2;
                  plVar21 = DAT_23eedddb8;
                  plVar16[-2] = lVar9;
                  plVar16[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
                  *(longlong **)(lVar9 + 8) = plVar16 + -2;
                  plVar16[3] = (longlong)plVar15;
                  *plVar21 = *plVar21 + 1;
                  plVar16[4] = (longlong)plVar21;
                  plVar21 = DAT_23ed6cd28;
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    plVar18 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar18 == (longlong *)0x0) goto LAB_23e7ea660;
                    *plVar18 = *plVar18 + 1;
                    DAT_23ed6a4c0 = plVar18;
                  }
                  plStack_80 = plVar21;
                  local_88 = plVar12;
                  lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&local_88);
                  if (lVar9 == 0) {
                    local_a8._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    local_a8._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    local_98[0] = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar16 = *plVar16 + -1;
                    plVar21 = local_98[0];
                    pcVar17 = (code *)local_a8._0_8_;
                    uVar13 = local_a8._8_8_;
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                      plVar21 = local_98[0];
                      pcVar17 = (code *)local_a8._0_8_;
                      uVar13 = local_a8._8_8_;
                    }
                    uVar22 = 0x79;
                    plVar16 = plVar10;
                    plVar15 = plVar12;
                    local_118 = plVar14;
                  }
                  else {
                    plVar16[5] = lVar9;
                    plVar15 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                    }
                    if (plVar15 == (longlong *)0x0) goto LAB_23e7ea5a0;
                    if ((local_e0 != (longlong *)0x0) &&
                       (*local_e0 = *local_e0 + -1, *local_e0 == 0)) {
                      (**(code **)(local_e0[1] + 0x30))(local_e0);
                    }
                    plVar8 = (longlong *)FUN_23e8bc2f0(local_140,DAT_23ed6ce40);
                    plVar16 = DAT_23ed6ccf0;
                    local_e0 = plVar15;
                    if (plVar8 != (longlong *)0x0) {
                      *(undefined4 *)(plVar6 + 5) = 0x7a;
                      plStack_80 = plVar16;
                      local_88 = plVar15;
                      plVar16 = (longlong *)FUN_23e94ed00(param_1,plVar8,&local_88);
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      if (plVar16 == (longlong *)0x0) goto LAB_23e7e9e50;
                      plVar8 = (longlong *)FUN_23e8bf9b0(plVar16,DAT_23ed6ccf8);
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                      }
                      if (plVar8 == (longlong *)0x0) goto LAB_23e7e9e50;
                      cVar5 = FUN_23a39bc50(param_1,local_140,plVar15,plVar8);
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      if (cVar5 == '\0') goto LAB_23e7e9e50;
                      lVar9 = *(longlong *)(param_1 + 0x10);
                      if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) == 0) &&
                           (*(int *)(lVar9 + 0x78) == 0)) ||
                          (iVar19 = Py_MakePendingCalls(), -1 < iVar19)) ||
                         (pcVar17 = *(code **)(param_1 + 0x60), pcVar17 == (code *)0x0))
                      goto LAB_23e7e9155;
                      goto LAB_23e7e996c;
                    }
LAB_23e7e9e50:
                    plVar21 = *(longlong **)(param_1 + 0x70);
                    pcVar17 = *(code **)(param_1 + 0x60);
                    uVar13 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar22 = 0x7a;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar16 = plVar10;
                    plVar15 = plVar12;
                    local_118 = plVar14;
                  }
                }
                goto LAB_23e7e99b0;
              }
              plVar18 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar18 != (longlong *)0x0) {
                *plVar18 = *plVar18 + 1;
                DAT_23ed6a4c0 = plVar18;
                goto LAB_23e7e8f31;
              }
LAB_23e7ea660:
              PyErr_PrintEx(0);
              Py_Exit(1);
              plVar6 = local_e0;
              local_e0 = local_118;
              goto LAB_23e7ea673;
            }
            pcVar17 = *(code **)(param_1 + 0x60);
            uVar13 = *(undefined8 *)(param_1 + 0x68);
            plVar21 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7e9d1a:
            uVar22 = 0x78;
            local_118 = plVar14;
            goto LAB_23e7e99b0;
          }
          PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator");
LAB_23e7e9b16:
          cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
          if (cVar5 != '\0') {
            if ((local_118 != (longlong *)0x0) && (*local_118 = *local_118 + -1, *local_118 == 0)) {
              (**(code **)(local_118[1] + 0x30))();
            }
            lVar9 = *local_108;
            *local_108 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(local_108[1] + 0x30))();
            }
            lVar9 = *(longlong *)(param_1 + 0x10);
            if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) == 0) &&
                 (*(int *)(lVar9 + 0x78) == 0)) || (iVar19 = Py_MakePendingCalls(), -1 < iVar19)) ||
               (*(longlong *)(param_1 + 0x60) == 0)) goto LAB_23e7e9b95;
            goto LAB_23e7eac86;
          }
          pcVar17 = *(code **)(param_1 + 0x60);
          uVar13 = *(undefined8 *)(param_1 + 0x68);
          plVar21 = *(longlong **)(param_1 + 0x70);
          local_98[0] = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          local_a8 = (undefined1  [16])0x0;
          if (local_118 == (longlong *)0x0) {
            uVar22 = 0x78;
          }
          else {
            uVar22 = 0x78;
LAB_23e7e99b0:
            local_98[0] = (longlong *)0x0;
            local_a8 = (undefined1  [16])0x0;
            lVar9 = *local_118;
            *local_118 = lVar9 + -1;
            if (lVar9 + -1 == 0) {
              (**(code **)(local_118[1] + 0x30))(local_118);
            }
          }
          lVar9 = *local_108;
          *local_108 = lVar9 + -1;
          if (lVar9 + -1 == 0) {
            (**(code **)(local_108[1] + 0x30))(local_108);
          }
        }
        goto LAB_23e7e9310;
      }
      FUN_23e915740(param_1,local_a8,DAT_23eeddcf0);
      plVar21 = local_98[0];
      pcVar17 = (code *)local_a8._0_8_;
      uVar13 = local_a8._8_8_;
LAB_23e7ea56c:
      local_e8 = local_b8;
      uVar22 = 0x77;
      goto LAB_23e7e9310;
    }
    cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
    if (cVar5 == '\0') goto LAB_23e7eae18;
    if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
    lVar9 = *plVar11;
    *plVar11 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    lVar9 = *(longlong *)(param_1 + 0x10);
    if ((((*(int *)(*(longlong *)(lVar9 + 0x28) + 0x160) != 0) || (*(int *)(lVar9 + 0x78) != 0)) &&
        (iVar19 = Py_MakePendingCalls(), iVar19 < 0)) && (*(longlong *)(param_1 + 0x60) != 0)) {
LAB_23e7ead72:
      plVar21 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar22 = 0x75;
      pcVar17 = *(code **)(param_1 + 0x60);
      uVar13 = *(undefined8 *)(param_1 + 0x68);
      local_e8 = local_b8;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e7e937e;
    }
    if (*(int *)(lVar9 + 0x68) == 0) {
      plVar10 = *(longlong **)(param_1 + 0x90);
    }
    else {
      PyEval_SaveThread();
      PyEval_AcquireThread(param_1);
      plVar10 = *(longlong **)(param_1 + 0x90);
    }
    if (plVar10 != (longlong *)0x0) {
      plVar12 = *(longlong **)(param_1 + 0x60);
      plVar8 = *(longlong **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x90) = 0;
      plVar14 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar10;
      *plVar10 = *plVar10 + 1;
      *(undefined8 *)(param_1 + 0x68) = 0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))();
      }
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      goto LAB_23e7ead72;
    }
    local_108 = local_110;
    plVar10 = local_130;
    plVar12 = local_128;
    plVar8 = local_c0;
    local_118 = local_138;
  }
  PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
               *(undefined8 *)(plVar7[1] + 0x18));
LAB_23e7e9f06:
  cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
  plVar14 = local_118;
  if (cVar5 != '\0') {
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    lVar9 = *plVar7;
    *plVar7 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    *local_140 = *local_140 + 1;
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
    lVar9 = *local_140;
    *local_140 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(local_140[1] + 0x30))(local_140);
    }
    if ((local_118 != (longlong *)0x0) &&
       (lVar9 = *local_118, *local_118 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(local_118[1] + 0x30))(local_118);
    }
    if ((local_108 != (longlong *)0x0) &&
       (lVar9 = *local_108, *local_108 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(local_108[1] + 0x30))(local_108);
    }
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if ((local_120 != (longlong *)0x0) &&
       (lVar9 = *local_120, *local_120 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(local_120[1] + 0x30))(local_120);
    }
    if ((local_b8 != (longlong *)0x0) &&
       (lVar9 = *local_b8, *local_b8 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(local_b8[1] + 0x30))(local_b8);
    }
    if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    if ((local_e0 != (longlong *)0x0) &&
       (lVar9 = *local_e0, *local_e0 = lVar9 + -1, lVar9 + -1 == 0)) {
      (**(code **)(local_e0[1] + 0x30))(local_e0);
    }
    lVar9 = *plVar1;
    *plVar1 = lVar9 + -1;
    if (lVar9 + -1 == 0) {
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    lVar9 = *plVar2;
    *plVar2 = lVar9 + -1;
    if (lVar9 + -1 != 0) {
      return local_140;
    }
    (**(code **)(plVar2[1] + 0x30))(plVar2);
    return local_140;
  }
LAB_23e7ea673:
  local_118 = plVar14;
  plVar21 = *(longlong **)(param_1 + 0x70);
  pcVar17 = *(code **)(param_1 + 0x60);
  uVar13 = *(undefined8 *)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x70) = 0;
  local_98[0] = (longlong *)0x0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  local_c0 = plVar8;
  if (plVar8 != (longlong *)0x0) {
LAB_23e7ea330:
    local_e8 = local_b8;
    uVar22 = 0x75;
    local_110 = local_108;
    local_138 = local_118;
    local_130 = plVar10;
    local_128 = plVar12;
    goto LAB_23e7e937e;
  }
  local_e8 = local_b8;
  uVar22 = 0x75;
  local_110 = local_108;
  local_138 = local_118;
  local_130 = plVar10;
  local_128 = plVar12;
  goto LAB_23e7e93b4;
LAB_23e7e9155:
  if (*(int *)(lVar9 + 0x68) == 0) {
    plVar8 = *(longlong **)(param_1 + 0x90);
  }
  else {
    PyEval_SaveThread();
    PyEval_AcquireThread(param_1);
    plVar8 = *(longlong **)(param_1 + 0x90);
  }
  plVar15 = plVar12;
  plVar16 = plVar10;
  local_118 = plVar14;
  if (plVar8 != (longlong *)0x0) {
    plVar16 = *(longlong **)(param_1 + 0x60);
    plVar15 = *(longlong **)(param_1 + 0x68);
    *(undefined8 *)(param_1 + 0x90) = 0;
    plVar21 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar8;
    *plVar8 = *plVar8 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
      (**(code **)(plVar16[1] + 0x30))();
    }
    if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
      (**(code **)(plVar21[1] + 0x30))(plVar21);
    }
    pcVar17 = *(code **)(param_1 + 0x60);
LAB_23e7e996c:
    plVar21 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    uVar22 = 0x78;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar16 = plVar10;
    plVar15 = plVar12;
    local_118 = plVar14;
    goto LAB_23e7e99b0;
  }
  goto LAB_23e7e8dbd;
LAB_23e7e9b95:
  if (*(int *)(lVar9 + 0x68) == 0) {
    plVar10 = *(longlong **)(param_1 + 0x90);
  }
  else {
    PyEval_SaveThread();
    PyEval_AcquireThread(param_1);
    plVar10 = *(longlong **)(param_1 + 0x90);
  }
  local_b8 = local_e8;
  if (plVar10 != (longlong *)0x0) {
    plVar12 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x90) = 0;
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(longlong **)(param_1 + 0x60) = plVar10;
    plVar14 = *(longlong **)(param_1 + 0x68);
    *plVar10 = *plVar10 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))();
    }
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))();
    }
LAB_23e7eac86:
    pcVar17 = *(code **)(param_1 + 0x60);
    plVar21 = *(longlong **)(param_1 + 0x70);
    uVar22 = 0x76;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    uVar13 = *(undefined8 *)(param_1 + 0x68);
    goto LAB_23e7e9310;
  }
  goto LAB_23e7e8b33;
LAB_23e7eae18:
  plVar21 = *(longlong **)(param_1 + 0x70);
  pcVar17 = *(code **)(param_1 + 0x60);
  uVar13 = *(undefined8 *)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar22 = 0x76;
  local_98[0] = (longlong *)0x0;
  local_e8 = local_b8;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  local_a8 = (undefined1  [16])0x0;
  if (plVar20 != (longlong *)0x0) {
LAB_23e7e9310:
    local_98[0] = (longlong *)0x0;
    local_a8 = (undefined1  [16])0x0;
    *plVar20 = *plVar20 + -1;
    if (*plVar20 == 0) {
      (**(code **)(plVar20[1] + 0x30))(plVar20);
    }
  }
  lVar9 = *plVar11;
  *plVar11 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
LAB_23e7e937e:
  local_98[0] = (longlong *)0x0;
  local_a8 = (undefined1  [16])0x0;
  lVar9 = *local_c0;
  *local_c0 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(local_c0[1] + 0x30))(local_c0);
  }
LAB_23e7e93b4:
  lVar9 = *plVar7;
  *plVar7 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  local_a8._8_8_ = uVar13;
  local_a8._0_8_ = pcVar17;
LAB_23e7e93fa:
  plVar7 = DAT_23ed6a4f8;
  local_98[0] = plVar21;
  if (plVar21 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar7 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar17 = _PyRuntime_exref;
    plVar7[2] = 0;
    plVar7[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar9 = *(longlong *)(pcVar17 + 0x1f8);
    *(undefined4 *)(plVar7 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)((longlong)plVar7 + 0x24) = uVar22;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar3 = plVar7[-1];
    puVar4 = *(undefined8 **)(lVar9 + 8);
    *puVar4 = plVar7 + -2;
    plVar7[-2] = lVar9;
    plVar7[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar9 + 8) = plVar7 + -2;
    plVar21 = plVar7;
    if ((local_98[0] != (longlong *)0x0) && (*local_98[0] = *local_98[0] + -1, *local_98[0] == 0)) {
      (**(code **)(local_98[0][1] + 0x30))(local_98[0]);
    }
  }
  else if ((longlong *)plVar21[3] != plVar6) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar7 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar17 = _PyRuntime_exref;
    plVar7[3] = (longlong)plVar6;
    *plVar6 = *plVar6 + 1;
    lVar9 = *(longlong *)(pcVar17 + 0x1f8);
    *(undefined4 *)(plVar7 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar7 + 0x24) = uVar22;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar3 = plVar7[-1];
    puVar4 = *(undefined8 **)(lVar9 + 8);
    *puVar4 = plVar7 + -2;
    plVar7[-2] = lVar9;
    plVar7[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar9 + 8) = plVar7 + -2;
    plVar7[2] = (longlong)plVar21;
    *plVar21 = *plVar21 + 1;
    plVar21 = plVar7;
    if ((local_98[0] != (longlong *)0x0) && (*local_98[0] = *local_98[0] + -1, *local_98[0] == 0)) {
      (**(code **)(local_98[0][1] + 0x30))();
    }
  }
  local_98[0] = plVar21;
  FUN_23e8bba40(plVar6,"oooooooooooo",plVar1,plVar2,local_140,local_138,local_110,local_128,
                local_130,local_120,local_e8,plVar16,plVar15,local_e0);
  if (DAT_23eedeb20 == plVar6) {
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    DAT_23eedeb20 = (longlong *)0x0;
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
    plVar7[0xf] = 0;
    plVar7 = local_98[0];
    uVar13 = local_a8._0_8_;
    uVar23 = local_a8._8_8_;
  }
  else {
    plVar7[0xf] = 0;
    plVar7 = local_98[0];
    uVar13 = local_a8._0_8_;
    uVar23 = local_a8._8_8_;
  }
  local_98[0] = (longlong *)0x0;
  local_a8 = (undefined1  [16])0x0;
  lVar9 = *local_140;
  *local_140 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(local_140[1] + 0x30))(local_140);
  }
  if ((local_138 != (longlong *)0x0) &&
     (lVar9 = *local_138, *local_138 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_138[1] + 0x30))(local_138);
  }
  if ((local_110 != (longlong *)0x0) &&
     (lVar9 = *local_110, *local_110 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_110[1] + 0x30))(local_110);
  }
  if ((local_128 != (longlong *)0x0) &&
     (lVar9 = *local_128, *local_128 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_128[1] + 0x30))(local_128);
  }
  if ((local_130 != (longlong *)0x0) &&
     (lVar9 = *local_130, *local_130 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_130[1] + 0x30))(local_130);
  }
  if ((local_120 != (longlong *)0x0) &&
     (lVar9 = *local_120, *local_120 = lVar9 + -1, lVar9 + -1 == 0)) {
    (**(code **)(local_120[1] + 0x30))(local_120);
  }
  if ((local_e8 != (longlong *)0x0) && (lVar9 = *local_e8, *local_e8 = lVar9 + -1, lVar9 + -1 == 0))
  {
    (**(code **)(local_e8[1] + 0x30))(local_e8);
  }
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if ((local_e0 != (longlong *)0x0) && (lVar9 = *local_e0, *local_e0 = lVar9 + -1, lVar9 + -1 == 0))
  {
    (**(code **)(local_e0[1] + 0x30))(local_e0);
  }
  local_a8._8_8_ = uVar23;
  local_a8._0_8_ = uVar13;
  lVar9 = *plVar1;
  *plVar1 = lVar9 + -1;
  local_98[0] = plVar7;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  lVar9 = *plVar2;
  *plVar2 = lVar9 + -1;
  if (lVar9 + -1 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,local_a8._0_8_,local_a8._8_8_,local_98[0]);
  return (longlong *)0x0;
}
